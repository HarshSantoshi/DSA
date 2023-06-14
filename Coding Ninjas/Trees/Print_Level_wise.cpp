#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printLevelWise(TreeNode <int>*root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*>p;
    p.push(root);
    while(!p.empty()){
        TreeNode<int>*curr = p.front();
        p.pop();
        cout<<curr->data<<":";
        int childcount = curr->children.size();
        if(childcount){
            cout<<curr->children[0]->data;
            p.push(curr->children[0]);
        }
        for(int i=1;i<childcount;i++){
            cout<<","<<curr->children[i]->data;
            p.push(curr->children[i]);
        }
        cout<<endl;
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}