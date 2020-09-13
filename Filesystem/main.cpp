#include <iostream>
#include <fstream>

#include "exportable.h"

using namespace std;


class TestObject : public Exportable {
private:
    int prvar1 = 1;
    int prvar2 = 2;

    virtual void setExportFields() override {
        fields.clear();
        insertField("prvar1", to_string(prvar1));
        insertField("prvar2", to_string(prvar2));
        insertField("puvar1", to_string(puvar1));
        insertField("puvar2", to_string(puvar2));
    }
    virtual void getImportFields() override {
        prvar1 = getFieldInt("prvar1");
        prvar2 = getFieldInt("prvar2");
        puvar1 = getFieldInt("puvar1");
        puvar2 = getFieldInt("puvar2");
    }

public:
    TestObject() {}

    int puvar1 = 0;
    int puvar2 = 0;

    void print() {
        cout << "prvar1 = " << prvar1 << endl
        << "prvar2 = " << prvar2 << endl
        << "puvar1 = " << puvar1 << endl
        << "puvar2 = " << puvar2 << endl;
    }

};


int main() {

    TestObject test;
    test.puvar1 = 0;
    test.puvar2 = 0;

    test.print();

    //test.exportObject("Test.txt");

    test.importObject("Test.txt");

    test.print();


/*
    ofstream outFile;
    outFile.open("example.txt");
    outFile << "Writing this to a file.\n";
    outFile << "Next line.\n";
    outFile << "Test Line 2. \n";
    outFile.close();

    ifstream inFile;
    inFile.open("example.txt");
    
    string line;
    while(getline(inFile, line)) {
        cout << line << "\n";
    }
    inFile.close();


    string testString = "";
    float testFloat = 200;
    testString = to_string(testFloat);
    float testFloat2 = std::stof(testString);

    cout << testString << endl;
    cout << testFloat2 << endl;
*/
    return 0;
}