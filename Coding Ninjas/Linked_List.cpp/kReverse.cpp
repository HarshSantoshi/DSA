
// Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

// For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

// For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
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
Node *kReverse(Node *head, int k)
{
	//Write your code here
    // Base case
    if (head== NULL){
return head;}
    if(k==0){
        return head;
    }
    // Step 1: Reverse first k nodes
    Node * next = NULL , * current = head, * prev = NULL;
    int count =0;
    
    while(current != NULL && count < k){
        next = current -> next;
        current -> next = prev;
        prev= current ; current = next;
        count ++;
    }
    //Step2 : Recursive Call
    if(next != NULL){
        head ->next = kReverse(next , k);
    }
    return prev;
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}