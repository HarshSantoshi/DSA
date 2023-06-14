#include<iostream>
using namespace std;
void printTable(int s, int e, int st) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    int i=s,c;
    while(s<=e){
        c= (5.0/9)*(s-32);
        cout<<s<<" "<<c<<endl;
        s=s+st;
    }
    return;
}
int main(){
    int start, end, step;
    cin >> start >> end >> step;
  
    printTable(start, end, step);

}


