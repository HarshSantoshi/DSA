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
void print(Node * head){

while(head !=NULL){
    cout<<head -> data<<" ";
    head =head-> next ;
    
}
}
void printReverse(Node *head)
{
    //Write your code here
     Node *prev =NULL;
    Node * current = head;
    Node * forward = NULL;
while(current !=NULL){
	forward = current -> next ;
    current -> next = prev;
     prev = current ;
    current = forward ;
    // cout<< prev<<" ";
    }
    head = prev;
    print(head);
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}