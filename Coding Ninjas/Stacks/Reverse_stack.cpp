#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.empty())
    {
        return;
    }
    int x = input.top();
    input.pop();
    cout<<"1"<<endl;
    reverseStack(input,extra);
    while(!input.empty())
    {
         cout<<"2"<<endl;
        extra.push(input.top());
        input.pop();
    }

     cout<<"3"<<endl;
    input.push(x);
    while(!extra.empty())
    {
         cout<<"4"<<endl;
        input.push(extra.top());
        extra.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}