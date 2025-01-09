#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Operation {
public:
    virtual string getName() = 0;
    virtual string getSign() = 0;
    virtual int calculation(int a, int b) = 0;
};
 
class Multiplication : public Operation {  
public:
    string getName() {
        return "Multiplication";
    }

    string getSign() {
        return "*";
    }

    int calculation(int a, int b) {
        return a * b;
    }
};

class Addition : public Operation {
public:
    string getName() {
        return "Addition";
    }

    string getSign() {
        return "+" ;
    }

    int calculation(int a, int b) {
        return a + b;
    }
};

class Subtraction : public Operation {
public:
    string getName() {
        return "Subtraction" ;
    }

    string getSign() {
        return "-";
    }

    int calculation(int a, int b) {
        return a - b;
    }
};

void main()
{

    Operation* Op1 = new Multiplication();
    Operation* Op2 = new Addition();
    Operation* Op3 = new Subtraction();

    int a = 100, b = 7;
    cout << a << " " << Op1->getSign() << " " << b << " = " << Op1->calculation(a, b) << endl;
    cout << a << " " << Op2->getSign() << " " << b << " = " << Op2->calculation(a, b) << endl;
    cout << a << " " << Op3->getSign() << " " << b << " = " << Op3->calculation(a, b) << endl;

}
