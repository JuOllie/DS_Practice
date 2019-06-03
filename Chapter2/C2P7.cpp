//Add 2 numbers in the form of linked lists 
//Recursive approach: O(N) space, O(M+ N) time


#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * next; 
};

class List
{
	public:
		Node* head;
		Node* tail;
		List()
		{
			head=NULL;
			tail=NULL;
		};
	void createList(int data);
	void displayList();
};


bool isIntersecting(Node* head1, Node* head2)
{

	Node* curr1=head1;
	Node* curr2=head2;

	while(curr1->next!=NULL || curr2->next!=NULL)
	{
		if(curr1->next!=NULL)
			curr1=curr1->next;

		if(curr2->next!=NULL)
			curr2=curr2->next;
	}

	if(curr1==curr2)
		return true;
	else return false;
}

Node* findIntersection(Node* head1, Node* head2)
{

	Node* ptr1=head1;
	Node* ptr2=head2;

	if(head1==NULL || head2==NULL )
		return NULL;

	if(isIntersecting(head1,head2)==false)
	{
		cout<<"DOES NOT INTERSECT"<<endl;
		return NULL;
	}
	else cout<<"DOES INTERSECT"<<endl;

	while(ptr1!=ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		if(ptr1==NULL) 
			ptr1=head2;
		if(ptr2==NULL)
			ptr2=head1;
		

	}
	return ptr1;
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





int main()
{
	int n, value,choice;
	List mylist;
	List n1;
	List n2;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Add 2 lists"<<endl;
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
		cout<<"Enter initial Linked List1 Size";
		cin>>n;
		while(n>=1)
		{
			cout<<"Enter data";
			cin>>value;
			n1.createList(value);
			--n;
		}

		cout<<"Enter initial Linked List2 Size";
		cin>>n;
		while(n>=1)
		{
			cout<<"Enter data";
			cin>>value;
			n2.createList(value);
			--n;
		}


		//Assume list 1 is longer and post of intersection is given
		cout<<"Enter joining position in longer list 1";
		cin>>n;
		Node* curr=n1.head;
		while(n>1)
		{
			curr=curr->next;
			--n;
		}
		n2.tail->next=curr;
	
		if(n1.head!=NULL && n2.head!=NULL)
		{
			Node* intersection=findIntersection(n1.head,n2.head);
			cout<<intersection->data;
	    }

		break;

		}
	}
	return -1;
}
