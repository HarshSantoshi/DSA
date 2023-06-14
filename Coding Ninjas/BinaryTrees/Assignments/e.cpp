#include <iostream>

using namespace std;

int main()
{

    long int t;
    long long int x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (x < y)
        {
            if (y % 2 == 1)
            {
                
                cout << (y*y) - x + 1 << endl;
            }
            else
            {
                cout << ((y - 1) * (y - 1) )+ x  << endl;
            }
        }
        else
        {
            if (x % 2 == 0)
            {
               
                cout << (x*x)- y + 1 << endl;
            }
            else
            {
                cout << ((x - 1) * (x - 1) ) + y << endl;
            }
        }
    }
    return 0;
}