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
Node * appendLastNToFirst(Node* head, int k){

    if(k==0 ||  head == NULL){
        return head;
    }
    Node * origTail = head;
    int count =0;
    while(origTail->next !=NULL){
        origTail = origTail->next;
        count++;
    }
    Node* newTail = head;
    int count2=0;
    while(count2!=count-k){
        newTail = newTail->next;
        count2++;
    }
    Node * newHead = newTail -> next;
    newTail -> next =NULL;
    origTail->next = head;
    return newHead;
    
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}