#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node * findmid(Node * head){
    Node * slow=head;
    Node * fast = head -> next;
    while(fast !=NULL && fast -> next !=NULL){
        fast =fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node * merge(Node * left , Node* right){
    if (left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    
    Node * ans = new Node(-1);
    Node * temp = ans;
    
    while(left != NULL && right != NULL){
        if(left->data  < right -> data){
            temp ->next = left;
            temp = left;
            left =left -> next;
        }
        else {
        temp -> next = right;
        temp =right;
        right = right -> next;
        }
    }
    while(left != NULL){
        temp ->next = left;
        temp = left;
        left =left -> next;
    }
    while(right != NULL){
        temp -> next = right;
        temp =right;
        right = right -> next;
    }
    ans = ans->next;
    return ans;
}


Node *mergeSort(Node *head)
{
	//Write your code here
    //Basecase 
    if(head ==NULL || head ->next ==NULL){
        return head;
    }
    //break LL in two halves
    Node * mid = findmid(head);
    Node* left =head;
    Node * right = mid->next;
    mid->next=NULL;
    // Recursive call to sort two halves
     left =mergeSort(left);
     right = mergeSort(right);
    
    // Merge Both left and right half
    Node * result = merge(left ,right);
    
    return result;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}