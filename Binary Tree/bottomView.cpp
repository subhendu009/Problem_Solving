/*
Bottom View of Binary Tree.

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, 
then print the later one in level traversal. For example, in the below diagram, 
3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2

Explanation:
First case represents a tree with 3 nodes and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be printed as such 3 1 2.

Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
	
Output: 40 20 60 30

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105


https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
*/


// Time Complexity : O(n log n)
// Extra Space : O(n) where n is the total number of nodes in the given binary tree.
std::map<int, int> leverOrderTraversal(TreeNode *root)
{
    std::map<int, int> distanceValueMap;
    
    if(!root)
    {
        return distanceValueMap;
    }
    
    // Map to store a pair of node pointer and its distance from root node.
    std::unordered_map<TreeNode*, int> nodeDistanceMap;
    
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    nodeDistanceMap[root] = 0;
    
    while(!nodeQueue.empty())
    {
        TreeNode *currentNode = nodeQueue.front();
        nodeQueue.pop();
        
        // Update value for the distance associated with current node.
        distanceValueMap[nodeDistanceMap[currentNode]] = currentNode->data;
        
        if(currentNode->left)
        {
            nodeQueue.push(currentNode->left);
			
			      // Add distance for the left node.
            nodeDistanceMap[currentNode->left] = nodeDistanceMap[currentNode] - 1;
        }
        
        if(currentNode->right)
        {
            nodeQueue.push(currentNode->right);
			
			      // Add distance for the right node.
            nodeDistanceMap[currentNode->right] = nodeDistanceMap[currentNode] + 1;
        }
    }
    
    return distanceValueMap;
}

//Function to return a list containing the bottom view of the given tree.
std::vector<int> bottomView(TreeNode *root)
{
	// Get the sorted map containing distance-value pairs.
	std::map<int, int> distanceValueMap = leverOrderTraversal(root);
	std::vector<int> numList;
	
	// Get all values from the distanceValueMap and add those to numList
	// which contains all numbers which appear in bottom view of the given tree.
	for(auto item : distanceValueMap)
	{
	    numList.push_back(item.second);
	}
	
	return numList;
}
