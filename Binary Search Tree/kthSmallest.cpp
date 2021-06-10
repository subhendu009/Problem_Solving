/*
230. Kth Smallest Element in a BST.

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Example 1:
----------------------------------------------------------------
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
----------------------------------------------------------------
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

Leetcode : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

// We will perform inorder traversal of the BST.
// Time Complexity : O(n) where n is the total number of nodes in the BST.
// Extra Space : O(h) where h is the height of the BST.

void inorderTraversal(TreeNode *root, int &k, int &kthSmallest)
{
  // Base case. return if root is NULL.
  if(!root)
  {
      return;
  }
  
  inorderTraversal(root->left, k, kthSmallest);
  // if k == 1, We have found the kth smallest element.
  // Update kthSmallest with root->data.
  if(1 == k)
  {
      kthSmallest = root->val;
  }

  --k;

  inorderTraversal(root->right, k, kthSmallest);
}


int kthSmallest(TreeNode* root, int k)
{
   int kthSmallest = INT_MIN;
   // Note : We are passing both k and kthSmallest as reference.
   inorderTraversal(root, k, kthSmallest);
   return kthSmallest;
}

