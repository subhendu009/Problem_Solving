/*
102. Binary Tree Level Order Traversal.

You are given a pointer to the root of a binary tree. You need to print the level order traversal of this tree. 
In level order traversal, we visit the nodes level by level from left to right. You only have to complete the function. 

For example:

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  
For the above tree, the level order traversal is 1 -> 2 -> 5 -> 3 -> 6 -> 4.

Geeksforgeeks : https://www.geeksforgeeks.org/level-order-tree-traversal/
Leetcode : https://leetcode.com/problems/binary-tree-level-order-traversal/
*/


// Definition for a binary tree node.
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity : O(n)
// Extra Space : O(n), where n is the total number of nodes in the binary tree.

std::vector<std::vector<int>> levelOrder(TreeNode* root) 
{
	std::vector<std::vector<int>> allNumberList;
	if(!root)
	{
		return allNumberList;
	}
	
	std::queue<TreeNode *> firstNodeQueue;
	std::queue<TreeNode *> secondNodeQueue;
	
	firstNodeQueue.push(root);
	
	while(!firstNodeQueue.empty())
	{
		std::vector<int> currentLevelNumList;
		
		while(!firstNodeQueue.empty())
		{
			TreeNode *currentNode = firstNodeQueue.front();
			currentLevelNumList.push_back(currentNode->val);
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
		allNumberList.push_back(currentLevelNumList);
	}
	
	return allNumberList;
}
