/*
Binary Tree to DLL.

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

TreeToList:

Example 1:

Input:
      1
    /  \
   3    2

Explanation: DLL would be 3<=>1<=>2

Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60

Explanation:  DLL would be  40<=>20<=>60<=>10<=>30.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

Geeksforgeeks : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/// ITERATIVE SOLUTION ////////////////////////////////////////////////////////////////////////////
TreeNode* binaryTreeToDLL(TreeNode* root)
{
    std::stack<TreeNode*> nodeStack;
    TreeNode* previousNode = nullptr;
    TreeNode* dllHead = nullptr;

    while (root || (false == nodeStack.empty()))
    {
        while(root)
        {
            nodeStack.push(root);
            root = root->left;
        }

        root = nodeStack.top();
        nodeStack.pop();
        TreeNode *nextNode = root->right;

        //process root data here
        if (nullptr == dllHead)
        {
            root->right = nullptr;
            root->left = nullptr;
            dllHead = root;
        }
        else
        {
            previousNode->right = root;
            root->left = previousNode;
        }

        previousNode = root;
        root = nextNode;
    }

    if(previousNode)
    {
        previousNode->right = nullptr;
    }

    return dllHead;
}

/// RECURSIVE SOLUTION ////////////////////////////////////////////////
void inorderTraversal(TreeNode* root, 
                      TreeNode*& previousNode,
                      TreeNode*& doublyLinkedListHead)
{
  if (!root)
  {
      return;
  }

  inorderTraversal(root->left, previousNode, doublyLinkedListHead);

  // Process current node here
  TreeNode *rightNode = root->right;

  if (doublyLinkedListHead)
  {
      previousNode->right = root;
      root->left = previousNode;
  }
  else
  {
      root->left = nullptr;
      root->right = nullptr;
      doublyLinkedListHead = root;
  }

  previousNode = root;

  inorderTraversal(rightNode, previousNode, doublyLinkedListHead);
}

TreeNode* binaryTreeToDLL(TreeNode* root)
{
  TreeNode* doublyLinkedListHead = nullptr;
  TreeNode* previousNode = nullptr;
  
  inorderTraversal(root, previousNode, doublyLinkedListHead);

  if (previousNode)
  {
      previousNode->right = nullptr;
  }

  return doublyLinkedListHead;
}
