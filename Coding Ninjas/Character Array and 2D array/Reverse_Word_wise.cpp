#include <iostream>

using namespace std;
int length(char input[])
{
    int len=0;
    
    for(int i=0;input[i]!='\0';i++)
    {
        len++;
    }
    
    return len;
}

void reverse(char input[],int start,int end)
{
    int i=start;
    int j=end;
    
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void reverseCompleteString(char input[])
{
    int i=0;
    int j=length(input)-1;
    
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void reverseStringWordWise(char input[])
{
    // Write your code here
    
    reverseCompleteString(input);
    
    int start=0;
    int end=0;
    int i;
    
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' ')
        {
            end=i-1;
            
            reverse(input,start,end);
            
            start=i+1;
        }
    }
    
    end=i-1;
    
    reverse(input,start,end);
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
