/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Leetcode :https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Geeksforgeeks :https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/
*/

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// We are solving this problem with fast and slow pointer approach.
// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if(n < 1)
	{
		return head;
	}
	
    ListNode *fastPtr = head;
    int index = 0;

    // Move fast pointer forward by n nodes.
    for( ; 
         (index < n) && fastPtr; 
         ++index)
    {
        fastPtr = fastPtr->next;
    }

    // If fast pointer points to NULL, there can be 4 cases.
    // Case 1. n is greater than the length of the given list. Don't delete any node. Just return head node.
    // Case 2: n is equal to the length of the linked list. So, we need to delete the head node.
    // Case 3: The list is empty. Return head pointer which is NULL.
    // Case 4: n is less than 1. Return head pointer.
    if(nullptr == fastPtr)
    {
        if(index == n)
        {
            ListNode *tempNode = head;
            head = head->next;
            delete tempNode;
        }

        return head;
    }

    ListNode *previousNode = nullptr;
    ListNode *slowPtr = head;

    // case 5: n is valid and we need to delete the node.
    // Reach the node just before the node to be deleted. Delete the next node. 
    while(nullptr != fastPtr)
    {
        fastPtr = fastPtr->next;
        previousNode = slowPtr;
        slowPtr = slowPtr->next;
    }

    previousNode->next = slowPtr->next;
    slowPtr->next = nullptr;
    delete slowPtr;
    return head;
}
