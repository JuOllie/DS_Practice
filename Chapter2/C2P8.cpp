//Find if a LL has a loop; also find the first node. 
//O(N) time


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
	Node* findFirstNode();

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


Node*  List::findFirstNode()
{
	Node* ptr1=head;
	Node* ptr2=head;
	int n;
	Node* temp=head; 

	cout<<"Enter the loop node position"<<endl;
	cin>>n;
	if(n==0)
		return NULL;
	while (n>1)
		{
			temp=temp->next;
			--n;
		}

	tail->next=temp;



	//Check if there is a loop
	while(ptr2!=NULL && ptr2->next!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
		if(ptr1==ptr2)
			break;
	}

	if(ptr1!=ptr2)
		return NULL;
	else 
		cout<<"There is a loop"<<endl;

	//Find the first node
	ptr1=head;
	while(ptr1!=ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}

	return ptr1;
}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Find Loop"<<endl;
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
		Node* result=mylist.findFirstNode();
		if(result==NULL)
			cout<<"No Loop"<<endl;
		else 
			cout<<result->data<<endl;

		
		break;

		}
	}
	return -1;
}
