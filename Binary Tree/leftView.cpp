/*
Left View of Binary Tree.

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of 
nodes visible when tree is visited from Left side. The task is to complete the function 
leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

        1
       / \
     2    3
    / \  / \
   4  5 6   7
   \
    8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000


https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
*/

struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode(int x)
  {
        data = x;
        left = right = nullptr;
  }
};

/////////////////////////////////////////////////////////////////////////////////////////
// Recursive solution using preorder traversal.

// Time Complexity : O(n)
// Extra Space : O(h), where n and h are the total number of nodes and height of the binary tree respectively.

void preOrderTraversal(TreeNode *root, std::vector<int> &numberList, 
                       std::vector<bool> &levelList, int level)
{
	if(!root)
	{
		return;
	}
	
	if(levelList.size() <= level)
	{
	    numberList.push_back(root->data);
	    levelList.push_back(true);
	}
	else
	{
		if(false == levelList[level])
		{
			numberList.push_back(root->data);
		}
	}

	preOrderTraversal(root->left, numberList, levelList, level + 1);
	preOrderTraversal(root->right, numberList, levelList, level + 1);
}

std::vector<int> leftView(TreeNode *root)
{
	std::vector<int> numberList;
	std::vector<bool> levelList;
	preOrderTraversal(root, numberList, levelList, 0);
	return numberList;
}


////////////////////////////////////////////////////////////////////////////////
// Iterative solution using level order traversal.
// Time Complexity : O(n)
// Extra Space : O(n), where n is the total number of nodes in the binary tree.

std::vector<int> leftViewOfBinaryTree(TreeNode *root)
{
	std::vector<int> leftViewNumList;
	if(!root)
	{
		return leftViewNumList;
	}

	std::queue<TreeNode *> firstNodeQueue;
	std::queue<TreeNode *> secondNodeQueue;

	firstNodeQueue.push(root);

	while(!firstNodeQueue.empty())
	{
		leftViewNumList.push_back(firstNodeQueue.front()->data);

		while(!firstNodeQueue.empty())
		{
			TreeNode* currentNode = firstNodeQueue.front();
			firstNodeQueue.pop();

			if(currentNode->left)
			{
				secondNodeQueue.push(currentNode->left);
			}

			if(currentNode->right)
			{
				secondNodeQueue.push(currentNode->right);
			}
		}

		std::swap(firstNodeQueue, secondNodeQueue);
	}

	return leftViewNumList;
}
