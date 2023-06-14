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
};

//Inherite properties of Vehicle to car
//Syntax is 
// class derived_Class_name : access-specifier  parent_Class_name{};


// Private properties will not be inherited
//Protected properties will become protected for class car
//Public properties will remain public
class Car : public Vehicle{
    public: 
    int numGears;
};

//Protected class can be accessed outside the class by only derived classes



//Private properties will not be inherited
//Protected properties will become protected for class bike
//Public properties will become protected
class Bike : protected Vehicle{

};




//Private properties will not be inherited
//Protected properties will become private for class cylce
//Public properties will become private
class Cylce : private Vehicle{

};

//If any access modifier is not mentioned then
//By default it is private