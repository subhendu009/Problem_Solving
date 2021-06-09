/*
104. Maximum Depth of Binary Tree.

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Explanation:
Test case 1: The tree is
       1
     /   \
   2       3
So, the height/depth would be 2.

Test case 2: The tree is
                           2
                            \
                             1 
                            /    
                          3
So, height/depth would be 3.

Geeksforgeeks : https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
Leetcode : https://leetcode.com/problems/maximum-depth-of-binary-tree/

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


// Recursive Solution
int maxDepth(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}


// Iterative Solution using two Queues - Level order traversal.
int maxDepth(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    std::queue<TreeNode*> firstQueue;
    std::queue<TreeNode*> secondQueue;

    firstQueue.push(root);

    int depth = 0;

    while (!firstQueue.empty())
    {
        while (!firstQueue.empty())
        {
            TreeNode* currentNode = firstQueue.front();
            firstQueue.pop();

            if (currentNode->left)
            {
                secondQueue.push(currentNode->left);
            }

            if (currentNode->right)
            {
                secondQueue.push(currentNode->right);
            }

        }

        ++depth;
        std::swap(firstQueue, secondQueue);
    }

    return depth;
}
