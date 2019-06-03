//Delete the element pointed at. Direct access; no access to the head node.
//Best: O(1) time. 


#include <iostream>
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
	void deleteNthNode();

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


void List::deleteNthNode()
{
	int pos;
	Node *temp;
	Node *curr=head;

	//Just to get the current position pointer
	cout<<"Enter position";
	cin>>pos;

	while(pos>1)
	{
		curr=curr->next;
		pos--;
	}

	if(curr==NULL || curr->next==NULL || curr=head)
		return;

	//Curr the current node pointed to 
	temp=curr->next;
	curr->data=curr->next->data;
	curr->next=curr->next->next;
	delete temp;
}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Delete nth node"<<endl;
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
		mylist.deleteNthNode();
		break;

		}
	}
	return -1;
}
