/*
148. Sort List.

Given the head of a linked list, return the list after sorting it in ascending order.
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

Leetcode : https://leetcode.com/problems/sort-list/
*/

// Definition for singly-linked list.
struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity : O(n log n) where n is the length of thr given list.
// Extra Space : O(1)

// Helper method to merge two sorted linked lists.
ListNode* mergeTwoLists(ListNode *firstList, ListNode *secondList)
{
    if(!firstList)
    {
        return secondList;
    }

    if(!secondList)
    {
        return firstList;
    }

    ListNode *resList = nullptr;

    if(firstList->val <= secondList->val)
    {
        resList = firstList;
        firstList = firstList->next;
    }
    else
    {
        resList = secondList;
        secondList = secondList->next;
    }

    ListNode *resListCurrentNode = resList;

    while(firstList && secondList)
    {
        if(firstList->val <= secondList->val)
        {
            resListCurrentNode->next = firstList;
            firstList = firstList->next;
        }
        else
        {
            resListCurrentNode->next = secondList;
            secondList = secondList->next;
        }

        resListCurrentNode = resListCurrentNode->next;
    }

    if(firstList)
    {
        resListCurrentNode->next = firstList;
    }
    else
    {
        resListCurrentNode->next = secondList;
    }

    return resList;
}

ListNode* sortList(ListNode* head) 
{
    // Base condition : If the list is empty or having only one node, return head.
    if(!head || (nullptr == head->next))
    {
        return head;
    }

    // Split the list into two equal parts.
    // Find the middle node using fast and slow pointer approach.
    ListNode *fastPtr = head;
    ListNode *slowPtr = head;
    ListNode *previousNode = nullptr;

    while(fastPtr && fastPtr->next)
    {
        previousNode = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Make thye last node if the first half pointint to NULL.
    previousNode->next = nullptr;

    // Recursively call sortList with the head nodes of the first half and the second half.
    ListNode* firstHalf = sortList(head);
    ListNode *secondHalf = sortList(slowPtr);

    // Merge the two sorted lists and return the merged list.
    return mergeTwoLists(firstHalf, secondHalf);
}
