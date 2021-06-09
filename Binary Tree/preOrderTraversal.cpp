// 144. Binary Tree Preorder Traversal
// Leetcode : https://leetcode.com/problems/binary-tree-preorder-traversal/
//
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
 

////////////////////////////   Recursive Solution ////////////////////////////////////
void _preorderTraversalHelper(TreeNode* root, std::vector<int>& numList) 
{
    if(!root)
    {
        return;
    }
        
    numList.push_back(root->val);
    _preorderTraversalHelper(root->left, numList);
    _preorderTraversalHelper(root->right, numList);
}
    
std::vector<int> preorderTraversal(TreeNode* root) 
{
    std::vector<int> numList;
    _preorderTraversalHelper(root, numList);
    return numList;
}

///////////////////////////////// Iterative Solution ///////////////////////////////////////    
std::vector<int> preorderTraversal(TreeNode* root) 
{
    std::vector<int> numList;
    if(!root)
    {
        return numList;
    }
        
    std::stack<TreeNode*> nodeStack;
    nodeStack.push(root);
        
    while(!nodeStack.empty())
    {
        root = nodeStack.top();
        nodeStack.pop();
        numList.push_back(root->val);
            
        if(root->right)
        {
            nodeStack.push(root->right);
        }
            
        if(root->left)
        {
            nodeStack.push(root->left);
        }
    }

    return numList;
}
