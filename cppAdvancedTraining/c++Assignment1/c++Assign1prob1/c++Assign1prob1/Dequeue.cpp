/*Define a Deque (Double Ended Queue) Class.
In double ended queue, insertions and deletions can be performed only at the ends (front and reat).
Support two data members front and rear and four member functions:
insert_front(), insert_rear(), delete_front() and delete_rear(). 
Derive Stack and Queue classes from Deque class. 
Use Doubly linked list (DLL) to represent Deque.
Use exception handling with user defined exception class.*/
#include<iostream>
#include<string>
using namespace std;
struct node
{
	string data;
	struct node * prev;
	struct node* next;
};
class Dequeue
{
	struct node* rear;
	struct node* front;
public:
	Dequeue()
	{
		rear = NULL;
		front = NULL;
	}
	~Dequeue()
	{
		struct node* temp;
		temp = rear;
		while (rear != front)
		{
			temp = rear;
			rear = rear->next;
			delete temp;
		}
		delete rear;
	}
	void insert_front(string );
	void insert_rear(string );
	string delete_front();
	string delete_rear();
	void display();
};
void Dequeue::insert_rear(string element)
{
	
	struct node *temp;
	temp = new node;
	temp->data = element;
	temp->prev = NULL;
	if (rear == NULL&&front==NULL)
	{
		temp->next = NULL;
		rear = front = temp;
	}
	else
	{
		temp->next = rear;
		rear->prev = temp;
		rear = temp;
	}
}
void Dequeue::insert_front(string element)
{
	 
	struct node *temp ;
	temp = new node;
	temp->data = element;
	cout << "in insert front" << endl;
	temp->next = NULL;
	if (rear == NULL && front == NULL)
	{
		temp->prev = NULL;
		rear =  temp;
		front = temp;
	}
	else
	{
		temp->prev = front;
		front->next = temp;
		front = temp;
	}
}
string Dequeue::delete_front()
{
	string tempString = " ";
	if (front == NULL)
	{
		cout << "no elements are there in the list" << endl;
		
	}
	else if (rear == front)
	{
		tempString = rear->data;
		delete rear;
		rear = front = NULL;
	}
	else
	{
		struct node *temp;
		temp = front;
		front = front->prev;
		 
		front->next = NULL;
		tempString = temp->data;
		delete temp;

	}
	return tempString;
}
string Dequeue::delete_rear()
{
	string tempString = " ";
	if (rear == NULL)
	{
		cout << "no elements are there in the list" << endl;

	}
	else if (rear == front)
	{
		tempString = rear->data;
		delete rear;
		rear = front = NULL;
	}
	else
	{
		struct node *temp;
		temp = rear;
		rear = rear->next;
		rear->prev = NULL;
		tempString = temp->data;
		delete temp;

	}
	return tempString;

}
void Dequeue::display()
{
	struct node * temp;
	temp = rear;
	while (rear != front)
	{
		temp = temp->next;
		cout<< temp->data;
		 
	}
	cout << temp->data;
}
void stack()
{
	Dequeue dequeueObj;
	int choice = 0;
	string element = "";
	while (true)
	{
		cout << "please choose any option from the following" << endl;
		cout << "1.push the element" << endl;
		cout << "2.pop the element" << endl;
		cout << "3.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter the element to be pushed" << endl;
			cin >> element;
			dequeueObj.insert_front(element);
			break;
		case 2:
			element= dequeueObj.delete_front();
			cout << " element popped is   " <<element<< endl;
			
			
			break;
		case 3:
			return;
		default:
			cout << "please enter a valid choice" << endl;
			break;
		}
	}
}
void queue()
{
	Dequeue dequeueObj;
	int choice = 0;
	string element = "";
	while (true)
	{
		cout << "please choose any option from the following" << endl;
		cout << "1.insert the element" << endl;
		cout << "2.delete the element" << endl;
		cout << "3.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter the element to be inserte" << endl;
			cin >> element;
			dequeueObj.insert_rear(element);
			break;
		case 2:
			element = dequeueObj.delete_front();
			cout << "enter the element deleted is   " << element << endl;
			break;
		case 3:
			return;
		default:
			cout << "please enter a valid choice" << endl;
			break;
		}
	}
}

int main()
{
	int choice = 0;
	while (true)
	{
		cout << "please choose any option from the following" << endl;
		cout << "1.implement a stack" << endl;
		cout << "2.implement a queue" << endl;
		cout << "3.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			stack();
			break;
		case 2:
			queue();
			break;
		case 3:
			exit(0);
		default:
			cout << "please enter a valid choice" << endl;
			break;
		}
	}
}