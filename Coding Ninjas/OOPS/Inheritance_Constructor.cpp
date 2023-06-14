/* If there are 3 classes A,B and C . B Inherite properties
of A and C inherite the properties of B */

/* If an object of class A is created then only constructor of A is called.
If an object of B is created then , firstly constructor of A is called then constructor 
of B is called.
If an object of class C is called then , first the constructor of A is called then connstructor
of B is called and then constructor of c is called .*/

#include<iostream> 
using namespace std;

class Vehicle
{

private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;
    // Vehicle(){
    //     cout<<"Default Constructor is called"<<endl;
    // }
    Vehicle(int a){
        cout<<"Parametrized Constructor is called"<<endl;
    }

    ~Vehicle(){
        cout<<"Destructor is called"<<endl;
    }
};

class Car:public Vehicle{
    public:
    int numGears;
    // Car(){
    //     cout<<"Car's Default constructor is called"<<endl;
    // }
    //Or
    Car() : Vehicle(5){
        cout<<"Car's default constructor is called"<<endl;
    }
    ~Car(){
        cout<<"Car's Destructor is called"<<endl;
    }


};

int main (){
    //Vehicle v;
    //v.color = "Black";


    Car c;
    c.color="White";
    c.numGears =5;
}