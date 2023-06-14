//bubble sort iterative
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
int len( Node * head){
    int len =0;
    Node * temp =head;
    while(temp!= NULL){
        temp = temp-> next ;
        len++;       
    }
    return len;
}

Node * swap (Node * ptr1 , Node * ptr2 ){
    Node * temp = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1->next = temp;
    return ptr2;
}
Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head == NULL){
        return NULL;
    }
    int length = len(head) -1;
    while(length--){
        Node * prev =NULL;
        Node * current = head;
        while(current -> next != NULL){
            if(current -> data >= current -> next -> data){
                if(prev== NULL){
                    Node * next = current -> next;
                    current -> next = next -> next;
                    next -> next = current ;
                    prev = next;
                    head = prev;
                }
                else {
                    Node * next = current -> next ;
                    prev-> next = next ;
                    current -> next = next -> next ;
                    next -> next = current ;
                    prev = next;
                }
                
            }
            else {
                prev = current ;
                current  =current -> next;
            }
        }
    }
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}