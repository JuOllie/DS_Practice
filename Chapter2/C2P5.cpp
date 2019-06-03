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


Node* addLists(Node* n1, Node* n2, int carry)
{
	if(n1==NULL && n2==NULL && carry==0)
		return NULL;

	int node_val=carry;

	if(n1!=NULL)
	{
		node_val=node_val+n1->data;
	}

	if(n2!=NULL)
	{
		node_val=node_val+n2->data;
	}

	Node * addedNode=new Node;
	addedNode->data=node_val%10;
	addedNode->next=addLists(n1? n1->next:NULL, n2? n2->next:NULL, node_val>9? 1:0 );

	return addedNode;

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
	
		Node* addedlist=addLists(n1.head,n2.head,0);
		
		while(addedlist)
		{
			cout<<addedlist->data<<"->";
			addedlist=addedlist->next;
		}

		break;

		}
	}
	return -1;
}
