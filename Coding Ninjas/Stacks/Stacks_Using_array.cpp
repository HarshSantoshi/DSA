#include<iostream>
#include<limits.h>
using namespace std ;
class Stacks{
private:
int * data;
int nextIndex;
int capacity;
public:
//Constructor:
Stacks(int totalSize){
    data= new int [totalSize];
    int capacity = totalSize;
    nextIndex = 0;
}
bool isEmpty(){
    // if(nextIndex == 0){
    //     return true;
    // }
    // else{
    //    return false;
    // }
    return (nextIndex ==0);
}
int size(){
    return nextIndex;
}
void push(int element){
    if(capacity == nextIndex){
        cout<<"Stack is Full"<<endl;
    }
    else{
        data[nextIndex] = element;
        nextIndex++;
    }
}
int pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    else {
    nextIndex--;
    return  data[nextIndex];
    }
}
int top(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
    }
    else{
        return data[nextIndex-1];
    }

}

};
int main(){
    Stacks s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    s.push(40);
    s.pop();
   cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
   cout<< s.isEmpty()<<endl;

}
