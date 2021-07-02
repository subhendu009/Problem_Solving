/* 
Question : Given a linked list consisting of L nodes and given a number N. 
           The task is to find the Nth node from the end of the linked list.
           
Example 1:

Input:
N = 2

LinkedList: 1->2->3->4->5->6->7->8->9

Output: 8

Explanation: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end is 8.  

Example 2:

Input:
N = 5

LinkedList: 10->5->100->5

Output: -1

Explanation: In the second example, there are 4 nodes in the linked list and we need to find 5th from the end. 
Since 'n' is more than the number of nodes in the linked list, the output is -1.

https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

*/

struct Node 
{
  int data;
  struct Node *next;
  
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
};

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    // Validate n, n >= 1
    if(n < 1)
    {
        return -1;
    }
           
    Node *fastPtr = head;
    int nodeCount = 0;
    
    // Traverse through the linked list and reach nth node from end.
    for( ; fastPtr && (nodeCount < n); ++nodeCount)
    {
        fastPtr = fastPtr->next;
    }
    
    // Check whether we have reached the end of the linked list or not.
    // Return if we have reached NULL.
    if(fastPtr == nullptr)
    {
        // If n is equal to the length of the linked list, return data from head node,
        // else n is greater than the length of the linked lis. Hence return -1.
        if(nodeCount == n)
        {
            return head->data;
        }
        
        return -1;
    }
    
    // Given n is valid and it is not equal to the length of the linked list.
    Node *slowPtr = head;
    while(fastPtr != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    
    return slowPtr->data;
}
