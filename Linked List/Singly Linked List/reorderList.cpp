/*
143. Reorder List.

You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 
Leetcode : https://leetcode.com/problems/reorder-list/
*/

#include <iostream>
#include <stack>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Method 1:
/*
1. Divide the list in two equal parts.
2. Reverse the second part.
3. Traverse both parts and create the new list.

Time Complexity : O(n) where n is the length of the given list.
Extra Space : O(1)
*/

// Helper function to reverse a list.
ListNode* reverseList(ListNode *head)
{
        ListNode *nextNode = nullptr;
        ListNode *previousNode = nullptr;

        while(head)
        {
            nextNode = head->next;
            head->next = previousNode;
            previousNode = head;
            head = nextNode;
        }

        return previousNode;
}

ListNode* reorderList(ListNode* head)
{
    // If the list is empty or has only one node, return.
    if((nullptr == head) || (nullptr == head->next))
    {
        return head;
    }

    ListNode *fastPtr = head;
    ListNode *slowPtr = head;
    ListNode *firstHalfLastNode = head;

    // Get middle node of the list.
    while(fastPtr && fastPtr->next)
    {
        firstHalfLastNode = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Chop out the first half.
    firstHalfLastNode->next = nullptr;

    // Reverse the second half.
    slowPtr = reverseList(slowPtr);

    // Traverse first and second half and create the reordered list.
    ListNode *resList = head;
    ListNode *currentResListNode = resList;
    head = head->next;

    while(head)
    {
        currentResListNode->next = slowPtr;
        currentResListNode = currentResListNode->next;
        slowPtr = slowPtr->next;

        currentResListNode->next = head;
        currentResListNode = currentResListNode->next;
        head = head->next;
    }

    // Append any left over nodes of the second half.
     currentResListNode->next = slowPtr;

    return resList;
}

// Method 2:
/*
Using a stack with extra space.

Time Complexity : O(n) where n is the length of the given list.
Extra Space : O(n)
*/

ListNode* reorderList(ListNode* head)
{
    if(nullptr == head)
    {
        return head;
    }

    std::stack<ListNode *> nodeStack;
    ListNode *currentNode = head;

    while(currentNode)
    {
        nodeStack.push(currentNode);
        currentNode = currentNode->next;
    }

    ListNode *resList = head;
    ListNode *resListCurrentNode = head;
    head = head->next;

    int maxNodeCount = nodeStack.size()/2;

    for(int nodeCount = 0; nodeCount < maxNodeCount; ++nodeCount)
    {
        resListCurrentNode->next = nodeStack.top();
        nodeStack.pop();
        resListCurrentNode = resListCurrentNode->next;

        resListCurrentNode->next = head;
        resListCurrentNode = resListCurrentNode->next;
        head = head->next;
    }

    resListCurrentNode->next = nullptr;
    return resList;
}
