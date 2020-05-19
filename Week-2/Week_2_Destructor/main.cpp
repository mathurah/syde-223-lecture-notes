#include <iostream>

class MyClass {
public:
    MyClass() {std::cout <<"MyClass constructed\n";}
    ~MyClass() {std::cout <<"MyClass destroyed\n";}
};

class ClassWithPointer {
private:
    int i;
    int *ip;
    MyClass *cp;
public:
    ClassWithPointer();
    ~ClassWithPointer();
};

ClassWithPointer::ClassWithPointer() {
    i = 10;
    ip = new int(20);
    cp = new MyClass;
}

ClassWithPointer::~ClassWithPointer() {

    delete ip;
    ip = NULL; //not very necessary, because no code will use this pointer after this anyway
    delete cp;
    cp = NULL; //not very necessary, because no code will use this pointer after this anyway

}
int main () {

    ClassWithPointer testObj;

    return 0;
}