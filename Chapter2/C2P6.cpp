//Palindrome List, Recursive approach
//Best: O(N) space, O(N)times


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
	bool findPalindrome(Node* curr, Node** head);

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


bool List::findPalindrome(Node *curr, Node** head)
{
	bool temp;

	if(curr==NULL)
		return true;

	temp=findPalindrome(curr->next,head);

	if(temp==false) 
		return false;

	if(curr->data!=(*head)->data)
		temp=false;
	else temp=true;
	*head=(*head)->next;

	return temp;

}

int main()
{
	int n, value,choice;
	List mylist;

	
	while (1)
	{	
		cout<<"Enter choice 1.Create 2.Display 3.Find if Palindrome"<<endl;
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

		cout<<mylist.findPalindrome(mylist.head,&mylist.head);
		break;

		}
	}
	return -1;
}
