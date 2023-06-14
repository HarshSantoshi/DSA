
//Pure virtual functions are those which does not have any function definition
#include <iostream>
using namespace std;
//Now the Vehicle class is called abstract class as we use a pure virtual function in it.
// Abstract class : Class which is incomplete , i.e. we haven't gave any function defition in the member function.
//We can not create object of such class.
class Vehicle
{
public:
    string color;
    //Below function is a virtual function
   /* 
    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
    */
    // Below function is a pure virtual function
    virtual void print ()=0;
};
//Whenver a class is inherited from a abstract base class then the derived class g=has two options:
// 1.Implement all the pure virtual functions
//2. Become a derived abstract class
class Car : public Vehicle
{
public:
    int numGears;

    //1
    void print()
    {
        cout << "Car" << endl;
    }
    
   //2.
   // Now the car class is also an abstract class.
};

int main()
{
    //Vehicle v;
    Car c;
    //v.print();
    c.print();
   
}