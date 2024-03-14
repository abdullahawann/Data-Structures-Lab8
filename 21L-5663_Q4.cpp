#include <iostream>
using namespace std;

class BST;

class TreeNode
{
	friend class BST;
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BST
{
    TreeNode*root;

public:
	BST()
	{
        root = 0;
    }

    bool insert(TreeNode*& t, int val)
	{
        if (t == NULL)
		{
            t = new TreeNode;
            t->data = val;
            t->left = NULL;
            t->right = NULL;
            return true;
        }

        else if (val < t->data)
		{
            insert(t->left, val);
        }

        else if(val > t->data)
		{
            insert(t->right, val);
        }

        else
        {
            return false;
        }
    }

    void insert(int val)
	{
        insert(root, val);
    }

    int length(TreeNode* t)
	{
	    if(t == 0)
		{
		    return false;
		}
	    else
		{
	    	return 1 + length(t->left) + length(t->right);
    	}
    }

    int length()
	{
	    return length(root);
    }

    void inorder(TreeNode* t)
	{
	    if(t != 0)
		{
		    inorder(t->left);
		    cout << t->data << " ";
		    inorder(t->right);
	    }
    }

    void inorder()
	{
	    inorder(root);
    }
};

int main()
{
    int n;
	int val;
    BST t;
    cout << "Enter the total amount of values you want to enter in binary tree : ";
	cin >> n;

    for (int i=0; i<n; i++)
	{
		cout << "Enter the " << i+1 << " value : ";
        cin >> val;
        t.insert(val);
    }
	cout << "The binary tree in order is : ";
    t.inorder();
    cout << endl;
    cout << "length of the binary tree is : " << t.length() << endl;
	cout << endl;

    system("pause");
	return 0;
}