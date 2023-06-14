/* Hybrid Inheritance : When combination of inheritances are used to 
make a derived class then it is called hybrid Inheritance . */
/* Eg: Car and Truck Innherit Properties of Vehicle and Bus inherite
properties of Car and Truck */
//The above example is also called diamond problem.
#include <iostream>
using namespace std;

class Vehicle
{

private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;
    Vehicle(){
        cout<<"Vehicle's Default Constructor is called"<<endl;
    }
    Vehicle(int a){
        cout<<"Parametrized Constructor is called"<<endl;
        maxSpeed = a;
    }

    ~Vehicle(){
        cout<<"Destructor is called"<<endl;
    }
    void print (){
        cout<<"Vehicle"<<endl;
    }
};
class Car:virtual public Vehicle{
    public:
    int numGears;
    Car(){
        cout<<"Car's Default constructor is called"<<endl;
      }
    //Or
    // Car() : Vehicle(5){
    //     cout<<"Car's default constructor is called"<<endl;
    // }
    ~Car(){
        cout<<"Car's Destructor is called"<<endl;
    }
    void print (){
        cout<<"NumTyres: "<<numTyres<<endl;
        cout<<"Color : "<<color<<endl;
        cout<<"NumGear : "<<numGears<<endl;
    }

};
//writing virtual ensure only one copy of base class(vehilce) in two
//derived classes ( car and Truck)
class Truck : virtual public Vehicle{
    public:
    Truck(){
        cout<<"Truck's constructor "<<endl;
    }
};

class Bus : public Car , public Truck{
    public:
    Bus(){
        cout<<"Bus's Constructor "<<endl;
    }
};
int main (){
    Bus b;
}
