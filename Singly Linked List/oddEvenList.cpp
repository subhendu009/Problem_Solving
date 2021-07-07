/*
328. Odd Even Linked List.

Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 
Constraints:
n == number of nodes in the linked list
0 <= n <= 104
-106 <= Node.val <= 106

Leetcode : https://leetcode.com/problems/odd-even-linked-list/
*/

ListNode* oddEvenList(ListNode* head) 
{
    if(!head || !head->next)
    {
        return head;
    }

    ListNode *oddList = head;
    ListNode *evenList = head->next;
    ListNode *evenListFirstNode = evenList;
    ListNode *currentNode = head->next->next;

    while(currentNode)
    {
        oddList->next = currentNode;
        oddList = currentNode;

        currentNode = currentNode->next;

        evenList->next = currentNode;
        evenList = currentNode;

        if(currentNode)
        {
            currentNode = currentNode->next;
        }
    }

    oddList->next = evenListFirstNode;
    return head;
}

// Another solution
ListNode* oddEvenList(ListNode* head) 
{
    if(!head)
    {
        return head;
    }

    ListNode *oddList = head;
    ListNode *evenListhead = head->next;
    ListNode *evenList = evenListhead;

    while(evenList && evenList->next)
    {
        oddList->next = oddList->next->next;
        oddList = oddList->next;
      
        evenList->next = evenList->next->next;
        evenList = evenList->next;
    }

    oddList->next = evenListhead;
    return head;
}
