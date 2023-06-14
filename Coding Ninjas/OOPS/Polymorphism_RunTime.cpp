
// To achieve run time polymorphism we need to use virtual functions.
// Virtual Function:These are the functions which are present in the
// base class and overwriiten in the derived class.
#include <iostream>
using namespace std;
class Vehicle
{
public:
    string color;
    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle
{
public:
    int numGears;
    void print()
    {
        cout << "Car" << endl;
    }
};

int main()
{
    Vehicle v;
    Car c;
    v.print();
    c.print();
    //Now vehicle object point to car object so print function of car is executed because of virtual function.
    Vehicle *v2 = new Car;
    v2->print();
}