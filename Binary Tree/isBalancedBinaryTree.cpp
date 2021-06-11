/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
       1
     /  \
   10    39
  /
5

An unbalanced tree
      1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3
     
Output: 0

Explanation: The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
 
Output: 1

Explanation: The max difference in height of left subtree and right subtree is 1. Hence balanced. 

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree

https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

Leetcode : https://leetcode.com/problems/balanced-binary-tree/
*/

// A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to find height of the given Binary Tree
int findHeight(Node *root, bool &bIsBalancedBinaryTree)
{
    // Base case
    // If the given node is NULL, return 0.
    if(nullptr == root)
    {
        return 0;
    }
    
    // Calculate height of left and right sub-trees
    int leftHeight = findHeight(root->left, bIsBalancedBinaryTree);
    int rightHeight = findHeight(root->right, bIsBalancedBinaryTree);
    
    // If the difference b/w the height of left and right sub-trees is greater than 1, update the flag.
    if(abs(rightHeight - leftHeight) > 1)
    {
        bIsBalancedBinaryTree = false;
    }
    
    return 1 + std::max(leftHeight, rightHeight);
}

// This function should return tree if passed  tree is balanced, else false.
bool isBalanced(Node *root)
{
    bool bIsBalancedBinaryTree = true;
    findHeight(root, bIsBalancedBinaryTree);
    return bIsBalancedBinaryTree;
}
