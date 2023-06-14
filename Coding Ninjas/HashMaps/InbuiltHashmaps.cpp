#include<iostream>
#include<unordered_map>
#include<string.h>
using   namespace std;

int main(){
    unordered_map <string , int > ourmap;
    pair<string , int > p ("abc" , 1);
    //insert
    ourmap.insert(p);
    ourmap["def"]=2;

    // access 
    cout<<ourmap["ghi"]<<endl;
     cout<<ourmap.size()<<endl;
    cout<<ourmap.at("ghi")<<endl;

    //check Presense
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present";
    }
    //size
    cout<<ourmap.size()<<endl;
    // erase
    ourmap.erase("abc");
    cout<<ourmap.size();



}