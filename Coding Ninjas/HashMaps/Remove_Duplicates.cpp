#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicate (int * a , int size){
    unordered_map<int , bool> seen;
    vector<int> output;
    for(int i=0;i<size;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        else{
            seen[a[i]]=true;
            output.push_back(a[i]);
        }
    }
    return output;
}

int main(){
    int a[11]= {1,3,5,2,8,2,2,8,1,4,3};
    vector<int> output = removeDuplicate(a , 11);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }

}