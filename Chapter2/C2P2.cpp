//Find the kth element from the end :O(N)
//Best: 2 pointer approach, no additional space except for a pointer.
//Can be used without having to find out the size of the linked list


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
	void findKFromEnd();

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


void List::findKFromEnd()
{
	int k;
	Node *curr=head;
	Node* ref=head;

	cout<<"Enter the value of k"<<endl;
	cin>>k;

	while(k)
	{
		if(ref==NULL)
		{
			cout<<"LL is too small"<<endl;
			return;
		}
		
		ref=ref->next;
		k--;
		
	}

	while(ref!=NULL)
	{
		curr=curr->next;
		ref=ref->next;
	}

	cout<<curr->data;
}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Find k from end"<<endl;
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
		mylist.findKFromEnd();
		break;

		}
	}
	return -1;
}
