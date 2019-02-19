/*single linked list implementation*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class SingleLL
{
	struct  node* start;
public:
	SingleLL();
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int,int );
	void insertBefore(int, int);
	int deleteFirst();
	int deleteLast();
	void deleteSpecific(int);
	void display();
	//~SingleLL();
};
SingleLL::SingleLL()
{
	start = NULL;
}
void SingleLL::insertFirst(int x)
{
	cout << "entered" << endl;
	struct node* temp;
	temp = new node;
	temp->data = x;
	if (start != NULL)
	{

		temp->next = start;
		start = temp;
	}
	else
	{
		temp->next = NULL;
		start = temp;
	}
	cout << "exit";
	
}
void SingleLL::insertLast(int x)
{
	struct node*temp, *cur;
	temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (start != NULL)
	{
		cur = start;
		while (cur != NULL&&cur->next != NULL)
			cur = cur->next;
		if (cur != NULL)
			cur->next = temp;
	}
	else
	{
		start = temp;
	}
}
void SingleLL::insertAfter(int x, int a)
{
	if (start != NULL)
	{
		
		{
			struct node*cur;
			cur = start;
			while (cur != NULL&&cur->data != a)
				cur = cur->next;
			if (cur != NULL)
			{
				struct node*temp;
				temp = new node;
				temp->data = x;
				temp->next = cur->next;
				cur->next = temp;

			}
			else
				cout << "the elemnet " << a << " not found in the list";
		}
	}
	else
		cout << "list is empty";
}
void SingleLL::insertBefore(int x, int a)
{
	if (start != NULL)
	{
		if (start->data == a)
		{
			struct node*temp;
			temp = new node;
			temp->data = x;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *cur;
			cur = start;
			while (cur != NULL&&cur->next != NULL&&cur->next->data != a)
			{
				cur = cur->next;
			}
			if (cur != NULL&&cur->next != NULL)
			{
				struct node *temp;
				temp = new node;
				temp->data = x;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "the element does not exist";
		}

	}
	else
		cout << "list is empty";
}
void SingleLL::display()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data<<endl;
		cur = cur->next;
	}
	
}
int SingleLL::deleteFirst()
{
	int x = -999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			delete start;
			start = NULL;
		}
		else
		{
			struct node *temp;
			temp = start;
			start = temp->next;
			x = temp->data;
			delete temp;

		}
	}
	else
		cout << "no elements present"<<endl;
	return x;
}
int SingleLL::deleteLast()
{
	int x=-999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *cur;
			cur = start;
			while (cur != NULL&&cur->next != NULL&&cur->next->next != NULL)
			{
				cur = cur->next;
			}
			if (cur != NULL&&cur->next != NULL)
			{
				struct node *temp;
				temp = cur->next;
				cur->next = NULL;
				x = temp->data;
				delete temp;
			}
			else
				cout << "the elemnet does not exist" << endl;
		}
	}
	else
		cout << "list is empty";
	return x;
}
int main()
{
	SingleLL sll;
	int choice=0;
	int x, temp;
	
	while (choice < 11)
	{
		cout << "choose the desired option" << endl;
		cout << "1.insert at the begining" << endl;
		cout << "2.insert at the end" << endl;
		cout << "3.insert after the element" << endl;
		cout << "4.insert at before the element" << endl;
		cout << "5.delete the first element" << endl;
		cout << "6.delete the last element" << endl;
		cout << "7.delete the specific element" << endl;
		cout << "8.display the linked list" << endl;
		cout << "9.traverse backwards" << endl;
		cout << "10.reverse the linked list" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "enter the element to be inserted" << endl;
			cin >> x;
			sll.insertFirst(x);
			break;
		case 2:
			cout << "enter the element to be inserted" << endl;
			cin >> x;
			sll.insertLast(x);
			break;
		case 3:
			cout << "enter the element to be inserted" << endl;
			cin >> x;
			cout << "enter the element after which you want to insert" << endl;
			cin >> temp;
			sll.insertAfter(x, temp);
			break;
		case 4:
			cout << "enter the element to be inserted" << endl;
			cin >> x;
			cout << "enter the element before which you want to insert" << endl;
			cin >> temp;
			sll.insertBefore(x, temp);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			sll.display();
			break;

		case 9:

			break;
		case 10:
			break;
		default:
			break;
		}
	}
	cout << "" << endl;
}