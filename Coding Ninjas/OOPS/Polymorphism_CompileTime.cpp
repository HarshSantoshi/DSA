#include<iostream>
using namespace std;

class Vehicle{
    public:
    string color;
    void print(){
        cout<<"Vehicle"<<endl;
    }
};

class Car:public Vehicle{
    public:
    int numGears;
    void print (){
        cout<<"Car"<<endl;
    }
};

int main(){
    Vehicle v;
    Car c;
    v.print();
    c.print();
    Vehicle * v1 = new Vehicle;         // Vehicle object created dynamically 
    Vehicle * v2;       //Vehicle pointer
    // v2 =&v;
    v2 = &c; // Base class object can point towards child class object but vice versa is not true.
    v2->print();  //we can access only those properties which are in base class.Therefore Vehicle will be printed.
    v1->print();
}