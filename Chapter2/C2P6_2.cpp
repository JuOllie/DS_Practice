//Palindrome List, Reversal approach
//Best: O(1) space, O(N)times


#include <iostream>
using namespace std;

struct Node
{
	char data;
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
	void createList(char data);
	void displayList();
	void reverseList(Node** head2);
	bool findPalindrome();

};


void List::createList(char data)
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


void List::reverseList(Node** head2)
{
	Node *prev=NULL;
	Node *curr=*head2;
	Node *next_node=curr->next;

	while(curr!=NULL)
	{
		curr->next=prev;
		prev=curr;
		curr=next_node;

		if(next_node==NULL)
			next_node=NULL;
		else
			next_node=curr->next;
		*head2=prev;
	}
}



bool List::findPalindrome()
{
	bool result=true;
	Node* ptr1=head;
	Node* ptr2=head->next;
	Node* mid_node; 
	Node* head2;

	if(head->next==NULL) 
		return true;

	//Fetch Mid-point
	while(ptr2!=NULL && ptr2->next!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}

	//To Reverse
	mid_node=ptr1;
	head2=mid_node->next;
	reverseList(&head2);

	mid_node->next=head2;

	//Traversal to check both halves
	ptr2=head;
	ptr1=mid_node->next;
	while(ptr1!=NULL)
	{
		if(ptr1->data!=ptr2->data)
		{
			result=false;
			break;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}


	reverseList(&head2);
	mid_node->next=head2;

	return result;

}

int main()
{
	int n,choice;
	char value ;
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

		cout<<mylist.findPalindrome();
		break;

		}
	}
	return -1;
}
