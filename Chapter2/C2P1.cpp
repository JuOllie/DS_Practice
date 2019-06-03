//Remove duplicates from an unordered linked list
//Best solution: Using unordered_Sets (hashing), O(N) time.

#include <iostream>
#include<bits/stdc++.h>

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
	void removeDuplicates();

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


void List::removeDuplicates()
{
	Node* curr=head;
	Node* prev=NULL;

	unordered_set<int> visited_value;

	while(curr!=NULL)
	{
		//FIRST OCCURENCE
		if(visited_value.find(curr->data)==visited_value.end())
		{
			visited_value.insert(curr->data);
			prev=curr;
			curr=curr->next;
		}

		else
		{
			prev->next=curr->next;
			delete curr;
			curr=prev->next;
		}
	}

}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Remove Duplicates"<<endl;
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
		mylist.displayList();
		break;

		case 3:
		mylist.removeDuplicates();
		break;

		}
	}
	return -1;