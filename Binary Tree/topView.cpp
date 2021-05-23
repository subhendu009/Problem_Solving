/*
Top View of Binary Tree.

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3

Output: 2 1 3

Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100

Output: 40 20 10 30 100

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105


https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

*/
struct Node
{
  int data;
  Node *left;
  Node *right;
  
  Node(int value)
  {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

std::map<int, int> levelOrderTraversal(Node *root)
{
    std::map<int, int> distanceValueMap;

    if(!root)
    {
        return distanceValueMap;
    }

    std::unordered_map<Node*, int> nodeDistanceMap;

    std::queue<Node *> nodeQueue;
    nodeQueue.push(root);
    nodeDistanceMap[root] = 0;

    while(!nodeQueue.empty())
    {
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();

        if(distanceValueMap.find(nodeDistanceMap[currentNode]) == distanceValueMap.end())
        {
            distanceValueMap[nodeDistanceMap[currentNode]] = currentNode->data;
        }

        if(currentNode->left)
        {
            nodeQueue.push(currentNode->left);
            nodeDistanceMap[currentNode->left] = nodeDistanceMap[currentNode] - 1;
        }

        if(currentNode->right)
        {
            nodeQueue.push(currentNode->right);
            nodeDistanceMap[currentNode->right] = nodeDistanceMap[currentNode] + 1;
        }
    }

    return distanceValueMap;
}
    
  std::vector<int> topView(Node *root)
  {
      std::map<int, int> distanceValueMap = levelOrderTraversal(root);
      std::vector<int> numList;

      for(auto distanceValuePair : distanceValueMap)
      {
          numList.push_back(distanceValuePair.second);
      }

      return numList;
  }
