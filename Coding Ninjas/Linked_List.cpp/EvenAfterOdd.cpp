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
Node *evenAfterOdd(Node *head)
{
	//write your code 
    Node * evenStart =NULL;
    Node * oddStart = NULL;
    Node* oddEnd = NULL , * evenEnd =NULL;
    Node * current = head;
    int currVal =0;
    if (head == NULL){
        return head;
    }
    if(head ->next == NULL){
        return head;
    }
while(current != NULL){
        currVal = current->data;
        if(currVal % 2 !=0){
            //Belong to Odd linked list
            if(oddStart == NULL){
                oddStart = current;
                oddEnd =oddStart;
            }
            else {
                oddEnd -> next = current;
            oddEnd = current;
            }
        }
        else {
            //Belong to Even linked list
            if(evenStart == NULL){
                evenStart = current;
                evenEnd = evenStart;
            }
            else {
                evenEnd -> next = current;
                evenEnd = current;
            }  
        }  
        current = current -> next;
    }
      if(evenStart == NULL || oddStart == NULL){
            return head;                                          
        }  
    // concatenating both linked lists
    oddEnd -> next = evenStart;
    evenEnd->next = NULL;
    head = oddStart;
    return head;
    
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}