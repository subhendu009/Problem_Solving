/*
Given a Binary Tree, find the In-Order Traversal of it. Collect all data and return as a vector.

Explanation:
Testcase1: The tree is
      1
     / \
   3    2
So, the in order would be 3 1 2

Testcase2: The tree is
                      10
                    /    \
                  20     30
                 /  \    /
               40   60  50
So, the inorder would be 40 20 60 10 50 30

https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
https://practice.geeksforgeeks.org/problems/inorder-traversal/1

Leetcode : https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive Solution.
void _inorderTraversal(TreeNode* root, std::vector<int> &valVector) 
{
	if(root)
	{
		_inorderTraversal(root->left, valVector);
		valVector.push_back(root->val);
		_inorderTraversal(root->right, valVector);
	}
}
    
std::vector<int> inorderTraversal(TreeNode* root) 
{
	std::vector<int> valVector;
	 _inorderTraversal(root, valVector);
	return valVector; 
}

//////////////////////////////////////////////////////////////////////////////////
// Iterative Solution.
std::vector<int> inorderTraversal(TreeNode* root) 
{
	std::vector<int> numberList;
	
	std::stack<TreeNode *> nodeStack;
	
  // Exit Condition : if root node is NULL and the stack is empty.
	while(root || (false == nodeStack.empty()))
	{
    // Keep on pushing left nodes to stack till we get a NULL node.
		while(root)
		{
			nodeStack.push(root);
			root = root->left;
		}

    // Get the current top of stack and add its value to numberList.
    // root should point to its right child now.
		root = nodeStack.top();
		nodeStack.pop();

		numberList.push_back(root->val);
		root = root->right;
	}
	
	return numberList;
}

/* *********************************************************************************   */
std::vector<int> inorderTraversal(TreeNode* root) 
{
	std::vector<int> numberList;
	
	std::stack<TreeNode *> nodeStack;
	
	while(true)
	{
		if(root)
		{
			nodeStack.push(root);
			root = root->left;
		}
		else
		{
			if(nodeStack.empty())
			{
				break;
			}
			
			root = nodeStack.top();
			nodeStack.pop();
			numberList.push_back(root->val);
			root = root->right;
		}
	}
	
	return numberList;
}
