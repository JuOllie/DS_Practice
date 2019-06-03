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
};

class List
{
	private:
		Node* head;
		Node* tail;
	public:
		List()
		{
			head=NULL;
			tail=NULL;
		};
	void createList(int data);
	void displayList();
	void insertNode(int data);
	void deleteNode();
	void deleteList();
	void searchList();

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


void List::displayList()
{
	Node *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}

}

void List::insertNode(int data)
{

	int choice,pos;
	Node* temp=new Node;
	Node* curr;

	temp->data=data;
	temp->next=NULL;

	cout<<"Enter choice 1. Beginning 3.Middle 2.End"<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1: 
		temp->next=head;
		head=temp;
		temp=NULL;
		break;

		case 2: ;
		tail->next=temp;
		tail=temp;
		temp=NULL;
		break;

		case 3:
		cout<<"Enter position";
		cin>>pos;

		curr=head;

		for(int i=2;i<pos;i++)
			curr=curr->next;
		temp->next=curr->next;
		curr->next=temp;
		temp=NULL;
		 break;		 
	}
}

void List:: deleteNode()
{
	int choice,pos;
	Node* temp=new Node;
	Node *curr;

	cout<<"Enter choice 1.Beginning 2.Middle 3.End"<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1: 
		temp=head;
		head=head->next;
		delete temp;
		break;

		case 2:
		curr=head;
		cout<<"Enter position";
		cin>>pos;

		for(int i=2;i<pos;i++)
			curr=curr->next;
		temp=curr->next;
		curr->next=curr->next->next;
		delete temp;
		break;

		case 3:
		curr=head;
		while(curr->next!=tail && curr!=tail)
			curr=curr->next;
		temp=tail;
		curr->next=NULL;
		tail=curr;
		delete temp;
		break;
	}
}

void List::deleteList()
{
	Node* temp=new Node;
	Node* curr=head;

	while(curr!=NULL)
	{
		temp=curr;
		curr=curr->next;
		delete temp;
	}

}

void List::searchList()
{
	int data,ctr=0;
	Node *curr=head;

	cout<<"Enter search value"<<endl;
	cin>>data;

	while(curr)
	{
		ctr++;
		
		if(curr->data==data)
		{
			cout<<"Found"<<data<<"at"<<ctr;
			return;
		}
		curr=curr->next;
	}

	cout<<"Not found:"<<data<<endl;

}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Insert 3.Display 4.Delete Node 5. Delete List 6.Search Element"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: 
			cout<<"Enter initial Linked List Size";
		cin>>n;
		while(n>=1)
		{
			cout<<"Enter data";
			cin>>value;
			mylist.createList(value);
			--n;
		}
		break;

		case 2: 
		cout<<"Enter data";
		cin>>value;
		mylist.insertNode(value);
		break;

		case 3:
		mylist.displayList();
		break;

		case 4:
		mylist.deleteNode();
		break;

		case 5:
		mylist.deleteList();
		break; 

		case 6:
		mylist.searchList();
		break;

		}
	}
	return -1;
}