//https://practice.geeksforgeeks.org/problems/k-sum-paths/1
#include<bits/stdc++.h>
#include<iostream>
#include <map>
#define ll long long 
class Node {
    public:
    int data;
    Node * left ;
    Node * right;
    Node (int data){
        this->data = data;
        left = NULL ;
        right = NULL;
    }
    
};
int ans =0;
map <ll , int >mp;
void solve(Node * root  , int k ,  ll currSum){
    if(root==NULL){
        return ;
    }
    currSum += root->data;
    ans +=mp[currSum - k ];
    mp[currSum]++;
    solve(root->left , k , currSum);
    solve(root->right , k , currSum);
    mp[currSum]--;
    currSum-=root->data;
}
int sumK(Node * root , int k){
    mp[0] =1;
    ll currSum =0;
    solve(root , k , currSum);
    return ans;
}
int main(){
    Node * root = new Node(6);
    
    int ans =sumK(root , 5);
    return ans;
}