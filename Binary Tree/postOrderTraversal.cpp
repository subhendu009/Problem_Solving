/*

Q. Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:  5 10 39 1

      1
     / \
   10   39
  /
 5
 
 Testcase1: The tree is
      19
     / \
   10   8
  /      \
11        13

So, the postorder would be 11 13 10 8 19.

Testcase2: The tree is
    11
   /
  15
 /
7

So, the postorder would be 7 15 11.

*/

// A binary tree node has data, pointer to left child and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

///////////////////   RECURSIVE SOLUTION //////////////////////////////////////////////////////
// The following recursive function will perform a post order traversal of the given binary tree
// and store data of each node in the passed vector.
vector <int>& _postOrder(Node* root, std::vector<int> &dataVector)
{
    //Base case - Tree is empty
    if(root == nullptr)
    {
        return dataVector;
    }
    
    dataVector = _postOrder(root->left, dataVector);
    dataVector = _postOrder(root->right, dataVector);
    dataVector.push_back(root->data);
    return dataVector;
}

vector <int> postOrder(Node* root)
{
  // Create a vector of int which will contain data of all nodes.
  std::vector<int> nodeDataVector;
  
  // Created vector will be passed by reference to the called recursive function
  return _postOrder(root, nodeDataVector);
}


///////////////////////////////  ITERATIVE SOLUTION ///////////////////////////////////////////////
// Two Stack approach .........................
// 
// Time Complexity : O(n)
// Extra Space : O(n) where n is the total number of nodes in the binary tree.

std::vector<int> postorderTraversal(Node* root)
{
    std::vector<int> numList;
    if (!root)
    {
        return numList;
    }

    std::stack<Node*> stackOne;
    std::stack<Node*> stackTwo;

    stackOne.push(root);

    while (!stackOne.empty())
    {
        Node* topNode = stackOne.top();
        stackOne.pop();
        stackTwo.push(topNode);

        if (topNode->left)
        {
            stackOne.push(topNode->left);
        }

        if (topNode->right)
        {
            stackOne.push(topNode->right);
        }
    }

    while (!stackTwo.empty())
    {
        numList.push_back(stackTwo.top()->data);
        stackTwo.pop();
    }

    return numList;
}
