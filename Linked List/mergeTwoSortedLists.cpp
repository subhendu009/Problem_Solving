/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Constraints:
Both the lists are sorted in non-decreasing order.

Leetcode : https://leetcode.com/problems/merge-two-sorted-lists/
Geeksforgeeks : https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1#
*/

//Link list Node
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

Node* mergeSortedLists(Node* head_A, Node* head_B)  
{ 
    // If any of the two given lists is empty, return the other list.
    if(nullptr == head_A)
    {
        return head_B;
    }
    
    if(nullptr == head_B)
    {
        return head_A;
    }
    
    Node *mergedListHead = nullptr;
    Node *currentNode = nullptr;
    
    // Create the head node of the merged list.
    if(head_A->data <= head_B->data)
    {
        mergedListHead = head_A;
        head_A = head_A->next;
    }
    else
    {
        mergedListHead = head_B;
        head_B = head_B->next;
    }
    
    currentNode = mergedListHead;
    
    // Traverse both lists till we reach end of any one list.
    while(head_A && head_B)
    {
        if(head_A->data <= head_B->data)
        {
            currentNode->next = head_A;
            head_A = head_A->next;
        }
        else
        {
            currentNode->next = head_B;
            head_B = head_B->next;
        }
        
        currentNode = currentNode->next;
    }
    
    // Create link with left over part of the list if any.
    if(head_A)
    {
        currentNode->next = head_A;
    }
    
    if(head_B)
    {
        currentNode->next = head_B;
    }
    
    return mergedListHead;
}  
