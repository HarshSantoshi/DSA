#include <iostream>
using namespace std;

#include <stack>

int* stockSpan(int *price, int n)  {

 

  int *S = new int[n];

      stack<int> st;

   st.push(0);

   S[0] = 1;

 

   for (int i = 1; i < n; i++) {

       while (!st.empty() && price[st.top()] < price[i])

           st.pop();

       S[i] = (st.empty()) ? (i + 1) : (i - st.top());

       st.push(i);

   }

   return S;

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}