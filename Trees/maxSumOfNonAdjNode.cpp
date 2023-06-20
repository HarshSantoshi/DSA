//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int>solve(Node * root ){
        if(root==NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int ,int>leftAns = solve(root->left);
        pair<int,int>rightAns = solve(root->right);
        
        pair<int,int>ans ;
        //include
        ans.first = root->data + leftAns.second + rightAns.second;
        //exclude
        ans.second = max(leftAns.first , leftAns.second) + max(rightAns.first , rightAns.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        // exclude sum , include sum
        pair<int,int>p;
        p = solve(root);
        return max(p.first , p.second);
        
    }
};