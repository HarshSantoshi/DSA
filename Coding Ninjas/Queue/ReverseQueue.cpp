#include <iostream>
using namespace std;

#include<queue>
void reverseQueue(queue <int> & q)
{
    // Base case
    if (q.empty())
        return;
 
    // Dequeue current item (from front) 
    int data = q.front();
    q.pop();
 
    // Reverse remaining queue 
    reverseQueue(q);
 
    // Enqueue current item (to rear) 
    q.push(data);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}