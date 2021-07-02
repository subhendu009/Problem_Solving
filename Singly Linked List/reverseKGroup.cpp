/*
25. Reverse Nodes in k-Group.

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:

Input: head = [1], k = 1
Output: [1]

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
 
Follow-up: Can you solve the problem in O(1) extra memory space?

Leetcode : https://leetcode.com/problems/reverse-nodes-in-k-group/
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

// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(1)

// Helper method to reverse the list.
ListNode* reverseList(ListNode *head)
{
    ListNode *previousNode = nullptr;
    ListNode *nextNode = nullptr;

    while(head)
    {
        nextNode = head->next;
        head->next = previousNode;
        previousNode = head;
        head = nextNode;
    }

    return previousNode;
}


ListNode* reverseKGroup(ListNode *head, int k)
{
    if(k < 2)
    {
        return head;
    }

    ListNode *resList = nullptr;
    ListNode *lastNode = nullptr;

    while(head)
    {
        ListNode *startNode = head;

        int count = 1;

        // Reach kth node.
        for(; head && (count < k); ++count)
        {
            head = head->next;
        }

        // If head is NULL, just append the remaining part and return.
        if(!head)
        {
            lastNode->next = startNode;
            break;
        }

        ListNode *nextNode = head->next;
        head->next = nullptr;

        // Reverse the group and append to the lastNode.
        if(resList)
        {
            lastNode->next = reverseList(startNode);
        }
        else
        {
            resList = reverseList(startNode);
        }

        lastNode = startNode;
        head = nextNode;
    }

    return resList;
}
