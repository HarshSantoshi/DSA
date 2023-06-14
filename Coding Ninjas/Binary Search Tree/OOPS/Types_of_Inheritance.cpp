/*
1. Single Inheritance: Only one parent and derived class
eg: car is derived class of vehicle
Syntax is : 
class car : access -Modifier Vehilce{};

2.Multilevel Inheritance:In this A is inherited by B and 
B is innherited by C
eg:Vehilce is inherited by car and car is inherited by honnda city
Synatx is:
class car:access-Modifier Vehicle{};
class hondacity:access-modifier Car{};

3.Hirarchial Inheritance : One parent class can be inherited by many 
derived classes
Eg:Vehilce class can be inherited by Car , Bike , Truck
Synatx is :
class Car:access-modifier Vehilce{};
class Bike:access-modifier Vehilce{};
class Truck:access-modifier Vehilce{};

4. Multiple Inheritance:Multiple base classes have same derived class
Eg: Teaching Assistant is a derived class of both Teacher and Student 
Synatx is :
class TA:access-modifier Teacher , access-modifier Student{};
In this first Teacher's costructor is called , then Student class 
Constructor is called and then constructor of TA is called.

*/

//Multiple Inheritance 
#include <iostream>
using namespace std;

class Teacher {
    public:
    string name;
    int age;
    void print (){
        cout<<"Teacher Class"<<endl;
    }
};

class Student {
    public:
    string name;
    void print (){
        cout<<"Student is called "<<endl;
    }
};

class TA:public Teacher , public Student{
    public:
    void print (){
        cout<<"TA is called"<<endl;
    }
};
int main(){
    TA a;
    a.print(); // TA print function is called

    /*If TA print is not present then we need to specify the 
    which class print function we are calling by scope resolution operator*/

    a.Student::print();
    a.Teacher::age;
}