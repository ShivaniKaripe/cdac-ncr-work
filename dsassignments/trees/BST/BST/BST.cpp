#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class BST
{
	struct node *start;
public:
	BST();
	node* insert(int,node *);
	void delete_element(int);
	void inorder();
	void preorder();
	void postorder();
	~BST();
	int findMax(node *);
	int findMin(node *);
	int height(node *);
	int noOfLeafNodes(struct node *);
	int noOfNonLeafNodes(node *);

};
BST::BST()
{
	start = NULL;
}
int  BST :: noOfLeafNodes(struct node *cur)
{
	if (cur == NULL)
		return 0;
	else if (cur->left == NULL&&cur->right == NULL)
		return 1;
	else
		return(noOfLeafNodes(cur->left) + noOfLeafNodes(cur->right));
}
int BST::noOfNonLeafNodes(node *cur)
{
	if (cur == NULL)
		return 0;
	else if (cur->left == NULL&&cur->right == NULL)
		return 0;
	else
		return(noOfNonLeafNodes(cur->left) + noOfNonLeafNodes(cur->right)+1);
}
int BST::findMax(node *cur)
{
	if (cur == NULL)
		return -1;
	else
	{
		while (cur->right != NULL)
			cur = cur->right;
		return (cur->data);
	}
}
int BST::findMin(node *cur)
{
	if (cur == NULL)
		return -1;
	else
	{
		while (cur->left != NULL)
			cur = cur->left;
		return (cur->data);
	}
}
int BST::height(node *cur)
{
	if (cur == NULL)
		return-1;
	else
	{
		return(std::max(height(cur->left), height(cur->right)) + 1);
	}
}
void BST::inorder()
{
	if (start != NULL)
		print_node_io(start);
	
}
void print_node_io(node *cur)
{
	if (cur != NULL)
	{
		print_node_io(cur->left);
		cout << cur->data;
		print_node_io(cur->right);
	}
}
void BST::preorder()
{
	if (start != NULL)
		print_node_pre(start);

}
void print_node_pre(node *cur)
{
	if (cur != NULL)
	{
		cout << cur->data;
		print_node_pre(cur->left);
		
		print_node_pre(cur->right);
	}
}
void BST::postorder()
{
	if (start != NULL)
		print_node_post(start);

}
void print_node_post(node *cur)
{
	if (cur != NULL)
	{
		
		print_node_post(cur->left);

		print_node_post(cur->right);
		cout << cur->data;
	}
}
node* BST::insert(int ele,node *cur)
{
	if (cur == NULL)
	{
		struct node*temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele < cur->data)
			insert(ele, cur->left);
		else
		{
			insert(ele, cur->right);
		}
		return cur;
	 
	}
}



