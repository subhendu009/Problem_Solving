/*
Finding middle element in a linked list.

Given a singly linked list of N nodes, find the middle of the linked list. 

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3

Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7

Leetcode : https://leetcode.com/problems/middle-of-the-linked-list/
*/

// Link list Node 
struct Node 
{
    int data;
    Node* next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Should return data of middle node. If linked list is empty, then  -1.

// Time Complexity : O(n) where n is the length of the given Singly Linked List.
// Extra Space : O(1)

int getMiddle(Node *head)
{
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    return(slowPtr ? slowPtr->data : -1);
}
