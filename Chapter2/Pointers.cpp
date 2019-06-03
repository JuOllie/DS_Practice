//Create a Linked List and Display Values
/**
BAD: 
https://www.geeksforgeeks.org/linked-list-set-1-introduction/
GOOD:
https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
https://www.programming9.com/programs/cpp-programs/300-cpp-code-to-implement-singly-linked-list
**/


#include <iostream>
//#include <conio.h>
//#include <stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node * next; 
}

class List
{
	private:
		Node* head;
		Node* tail;
	public:
		Node()
		{
			head=NULL;
			tail=NULL;
		}
	void createList(int data);
	void displayList();

};


void List::createList(int data)
{
	Node* temp= new Node;
	temp->data=data;
	temp->next=NULL;

	if(head==NULL)
	{
		head=temp;
		tail=temp;
		temp=NULL;
	}

	else
	{
		tail->next=temp;
		tail=temp;
		temp=NULL;
	}

}

void displayList()
{
	Node *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}

}


int main()
{
	int n, value;
	List mylist;

	cout<<"Enter initial Linked List Size";
	cin>>n;



	while(n>=1)
	{
		cout<<"Enter data";
		cin>>value;
		mylist.createList(value);

	}
	mylist.displayList();

	return -1;
}