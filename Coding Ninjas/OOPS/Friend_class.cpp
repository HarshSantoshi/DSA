#include <iostream>
using namespace std;
void test();

class Bus{
    public:
    void print();
};
class Truck{
    private:
    int x;
    protected:
    int y;
    public:
    int z;
    friend void Bus::print(); // compiler will give an error as till now it does not know about class Bus.
                            // So we need to declare it before.
    friend void test();
};
void Bus::print(){
    Truck t;
    t.x = 12;
    t.y= 20;
    cout<<t.x<<" "<<t.y<<endl;
}
void test(){
    Truck t;
    t.x = 12;
    t.y= 20;
    cout<<t.x<<" "<<t.y<<endl;
}
int main(){
    Bus b;
    b.print();
    test();
}