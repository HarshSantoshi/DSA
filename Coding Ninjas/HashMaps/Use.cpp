#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //Creation
    unordered_map<string,int>m;
    //Insertion 
    //1
    pair<string,int>pair1=make_pair("Harsh" ,5);
    m.insert(pair1);
    //2
    pair<string,int>pair2("Santoshi" ,10);
    m.insert(pair2);
    //3
    m["is"]=2;
    m["Harsh"]=3;

    //Search
    cout<<m["Harsh"]<<endl;
    cout<<m.at("Harsh")<<endl;

    //cout<<m.at("NoKey")<<endl;        //Error
    cout<<m["NoKey"]<<endl;


   //Size
   cout<<m.size()<<endl;

   //to check presence
   cout<<m.count("Harsh")<<endl;
   cout<<m.count("No")<<endl;

   //erase
   m.erase("is");
   cout<<m.size()<<endl;

   //iterating 
   unordered_map<string,int>:: iterator it = m.begin();
   while(it!=m.end()){
    cout<<it->first <<" "<<it->second<<endl;
    it++;
   }
}