

#include <iostream>
#include <vector>

using namespace std;

std::vector<int*> v;

class test {
public:
    static int index;
    const int i;
    test() : i(++index) {}
};

int test::index = 0;

int main() {

    test* t1 = new test();
    test* t2 = new test();
    test* t3 = new test();
    
    vector<test*> t;
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);

    cout << "Printing vector whatevers" << endl;
    cout << t[0]->i << endl;
    cout << t[1]->i << endl;
    cout << t[2]->i << endl;

    t.erase(t.begin()+1);

    cout << "Printing vector whatevers after erasing middle one" << endl;
    cout << t[0]->i << endl;
    cout << t[1]->i << endl;

    cout << "Printing value from pointer" << endl;
    cout << t2->i << endl;

    delete t2;
    cout << "Printing value from pointer after deletion" << endl;
    cout << t2->i << endl;

    return 0;
}