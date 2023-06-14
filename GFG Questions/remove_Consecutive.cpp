 #include<iostream>
 using namespace std;
 string removeConsecutiveCharacter(string s)
    {
        // code here.
        string ans="";
        int m=0;
        int i =0;
        while(i<s.length()){
            
            if(i==0){
                ans[m]=s[i];
                m++;
                i++;
            }
            
            if(s[i-1]==s[i]){
                i++;
            }
            else{
                ans[m]=s[i];
                m++;
                i++;
            }
        }
        return  ans;
    }

    int main(){
        string s;
        cin>>s;
        string a = removeConsecutiveCharacter(s);
        cout<<a;
    }