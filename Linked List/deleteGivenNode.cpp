/*
Q. Given a pointer to a node, delete that node of a singly linked list. Is it possible in all scenarios?  
Ans. https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
     https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
 
     Cases:  
          1. The given node is the last node. We can only solve this case by traversing the entire list.  
          2. The given node is not the last node. Copy data from the next node to the given node and delete the next node. 

     This works with the assumption that the node is a valid linked list node.  
*/

struct Node 
{
  int data;
  Node *next;
  
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
};

// This function should delete node from linked list. The function may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   Node *nextNode = node->next;
   node->data = nextNode->data;
   node->next = nextNode->next;
   delete nextNode;
}
