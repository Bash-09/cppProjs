#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

class Field {

public:
    Field(std::string name, std::string value) : name(name), value(value) {}
    Field() {}

    std::string name;
    std::string value;
};

class Exportable {
protected:

    std::unordered_map<std::string, Field> fields;

    float       getFieldFloat(std::string key)  {return std::stof(fields[key].value);}
    double      getFieldDouble(std::string key) {return std::stod(fields[key].value);}
    int         getFieldInt(std::string key)    {return std::stoi(fields[key].value);}
    std::string getFieldString(std::string key) {return fields[key].value;}
    void insertField(std::string name, std::string value) {
        fields.insert({name, {name, value}});
    }

    virtual void setExportFields() = 0; //Just set fields for all the variables
    virtual void getImportFields() = 0; //Set variables from getters (using)

public:
    void exportObject(std::string filename) {
        setExportFields();
        std::ofstream outFile;
        outFile.open(filename);
        
        for(auto i = fields.begin(); i != fields.end(); i++) {
            outFile << i->second.name << " = \"" << i->second.value << '"' << std::endl;
        }

        outFile.close();
    }

    void importObject(std::string filename) {
        using namespace std;
        fields.clear();
        ifstream inFile;
        inFile.open(filename);
        if(inFile.fail()) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }

        string line;
        while(getline(inFile, line)) {
            regex reg_name("\\s*([^\\s]*)\\s*=");
            smatch sm_name;
            string name;

            regex reg_value("= \"(\\w+)\"");
            smatch sm_value;
            string value;

            if(regex_search(line, sm_name, reg_name) && sm_name.size() > 1) {
                if(regex_search(line, sm_value, reg_value) && sm_name.size() > 1) {
                    name = sm_name.str(1);
                    value = sm_value.str(1);

                    insertField(name, value);
                }
            }

        }
        getImportFields();
    }

};