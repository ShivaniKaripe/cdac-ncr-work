/*AVL trees implementation*/
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class AVL
{
	struct node *start;
public:
	AVL()
	{
		start = NULL;
	}
	node *insert(int, node *);
	node *delete_node(int, node*);
	node * l_rotation(node*);
	node * r_rotation(node*);
	node * rl_rotation(node*);
	node * lr_rotation(node*);
	node * balance(node *cur);
	int balance_factor(node *);
	void inorder(node *);
	int hieght(node *);
	node *nodeStart()
	{
		return start;
	}
	~AVL()
	{

	}
};
node* AVL::l_rotation(node *cur)
{
	node *temp;
	temp = cur->right;
	cur->right = temp->left;
	temp->left = cur;
	return temp;

}
node *AVL::r_rotation(node *cur)
{
	node *temp;
	temp = cur->left;
	cur->left = temp->right;
	temp->right = cur;
	return temp;
}
node * AVL::lr_rotation(node*cur)
{
	node *temp;
	temp = cur->left;
	cur->left = l_rotation(temp);
	temp = r_rotation(cur);
	return temp;
}
node *AVL::rl_rotation(node*cur)
{
	node *temp;
	temp = cur->right;
	cur->right = r_rotation(temp);
	temp = l_rotation(cur);
	return temp;
}
node *AVL::balance(node*cur)
{
	if (balance_factor(cur) > 1)
	{
		if (balance_factor(cur->left) == 1)
			cur = r_rotation(cur);
		else
			cur = lr_rotation(cur);
	}
	if (balance_factor(cur) < -1)

	{
		if (balance_factor(cur->right) == -1)
			cur = l_rotation(cur);
		else
			cur = rl_rotation(cur);
	}
	return cur;
}
int AVL::balance_factor(node *cur)
{
	return(hieght(cur->left) - hieght(cur->right));
}
int AVL::hieght(node *cur)
{
	if (cur == NULL)
		return 0;
	else if (cur->left == NULL && cur->right == NULL)
		return 1;
	else
		return(std::max(hieght(cur->left), hieght(cur->right)) + 1);
}
node *AVL::insert(int e, node*cur)
{
	if (cur == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = e;
		temp->left = NULL;
		temp->right = NULL;
		cur = temp;
	}
	else
	{
		if (e < cur->data)
			cur->left=insert(e, cur->left);
		else if (e > cur->data)
			cur->right=insert(e, cur->right);
	}
	cur = balance(cur);
	return cur;
}
int findMax(node *cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	else
		return -1;
}
node* AVL::delete_node(int e, node *cur)
{
	if (cur == NULL)
		cout << "tree is emty" << endl;
	else
	{
		if (e < cur->data)
			cur->left = delete_node(e, cur->left);
		else if (e > cur->data)
			cur->right = delete_node(e, cur->right);
		else
		{
			if (cur->left != NULL && cur->right != NULL)
			{
				cur->data = findMax(cur->left);
				cur->left = delete_node(cur->data, cur->left);
			}
			else
			{
				struct node *temp;
				temp = cur;
				if (cur->left == NULL)
					cur = cur->right;
				else
					cur = cur->left;
				delete temp;
			}
		}
	}
	cur = balance(cur);
	return cur;
}
void printNode(node *cur)
{
	if (cur != NULL)
	{
		printNode(cur->left);
		cout << cur->data;
		printNode(cur->right);
	}
}
void AVL::inorder(node *cur)
{
	printNode(cur);
}
int main()
{
	AVL avl;
	struct node *cur;
	cur = avl.nodeStart();
	int choice,element;
	do
	{
		cout << "choose an option provided below" << endl;
		cout << "1.Insert an element\n2.Delete an element\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to be inserted" << endl;
			cin >> element;
			avl.insert(element, cur);
			break;
		case 2:
			cout << "Enter the element to be deleted " << endl;
			cin >> element;
			avl.delete_node(element, cur);
			break;
		case 3:
			 
			avl.delete_node(element, cur);
			avl.inorder(cur);
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	
	} while (choice < 4);
	return 0;
}
