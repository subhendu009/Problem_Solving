/*
Given a singly linked list, delete middle of the linked list. 
For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.

If there are even number of nodes, there would be two middle nodes, we need to delete the second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL.

Geeksforgeeks:
    https://www.geeksforgeeks.org/delete-middle-of-linked-list/
    https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
*/

struct SinglyListNode
{
    int data;
    SinglyListNode* next;

    SinglyListNode(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Deletes middle of linked list and returns head of the modified list

// Time Complexity : O(n) where n is the length of the list.
// Extra Space : O(1)

SinglyListNode* deleteMiddleNode(SinglyListNode* head)
{
    SinglyListNode* slowPtr = head;
    SinglyListNode* fastPtr = head;
    SinglyListNode* previousNode = nullptr;

    // Traverse the list. Increment slowPtr by 1 node and fastPtr by 2 nodes.
    while (fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        previousNode = slowPtr;
        slowPtr = slowPtr->next;
    }

    // If the given list is not empty, delete the middle node.
    if (previousNode)
    {
        previousNode->next = slowPtr->next;
        delete slowPtr;
    }

    return head;
}
