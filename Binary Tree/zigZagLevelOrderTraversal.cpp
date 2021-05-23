/* 
103. Binary Tree Zigzag Level Order Traversal.

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

*/


//Structure of the node of the binary tree is as
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// Time Complexity : O(n)
// Extra Space : O(n), where n is the total number of nodes in the binary tree.
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
	std::vector<std::vector<int>> allLevelsNumberList;
	
	if(!root)
	{
		return allLevelsNumberList;
	}

	std::stack<TreeNode *> firstStack;
	std::stack<TreeNode *> secondStack;

	firstStack.push(root);

	while(!firstStack.empty() || !secondStack.empty())
	{
		TreeNode *currentNode = nullptr;
		
		std::vector<int> oddLevelNumList;
		
		while(!firstStack.empty())
		{
			currentNode = firstStack.top();
			firstStack.pop();
			oddLevelNumList.push_back(currentNode->val);

			if(currentNode->left)
			{
				secondStack.push(currentNode->left);
			}

			if(currentNode->right)
			{
				secondStack.push(currentNode->right);
			}
		}
		
		allLevelsNumberList.push_back(oddLevelNumList);
		
		std::vector<int> evenLevelNumList;

		while(!secondStack.empty())
		{
			currentNode = secondStack.top();
			secondStack.pop();
			evenLevelNumList.push_back(currentNode->val);

			if(currentNode->right)
			{
				firstStack.push(currentNode->right);
			}

			if(currentNode->left)
			{
				firstStack.push(currentNode->left);
			}
		}
		
		if(evenLevelNumList.size())
		{
			allLevelsNumberList.push_back(evenLevelNumList);
		}
	}

	return allLevelsNumberList;
}
