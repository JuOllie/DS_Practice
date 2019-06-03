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
	void partitionList();

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


void List::partitionList()
{
	int part_value;
	Node *curr1=head;
	Node *head2;
	Node *tail2;

	cout<<"Enter partition value"<<endl;
	cin>>part_value;

	if(curr1->next==NULL)
	{
		cout<<curr1->data;
		return;
	}

	head2=new Node;
	head2->data=curr1->data;
	head2->next=NULL;
	tail2=head2;

	curr1=curr1->next;


	while(curr1!=NULL)
	{
		Node * addNode=new Node;
		addNode->data=curr1->data;
		addNode->next=NULL;

		if (curr1->data<part_value)
		{
			addNode->next=head2;
			head2=addNode;
		}

		else
		{
			tail2->next=addNode;
			tail2=addNode;
		}

		curr1=curr1->next;
	}


	curr1=head2;
	while(curr1!=NULL)
	{
		cout<<curr1->data<<"->";
		curr1=curr1->next;
	}


}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Partition List"<<endl;
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
		mylist.partitionList();
		break;

		}
	}
	return -1;
}
