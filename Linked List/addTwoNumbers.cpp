/*
Q. Given two numbers represented by two linked lists, write a function that returns a sum list. 
The sum list is a linked list representation of addition of two input numbers. Expected Space Complexity O (1).

Examples:
Input:
L1 = 5 -> 6 -> 3 -> NULL
L2 = 8 -> 4 -> 2 -> NULL
Output: 1 -> 4 -> 0 -> 5 -> NULL

Input:
L1 = 1 -> 0 -> 0 -> NULL
L2 = 9 -> 1 -> NULL
Output: 1 -> 9 -> 1 -> NULL

https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists-set-3/?ref=rp
*/

#include <iostream>
#include <stack>

using std::cout;
using std::endl;

// Singly Linked List Node
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

// Function to insert data in front of the Singly Linked List.
SinglyListNode* insertAtFront(SinglyListNode* pListHead, int data)
{
    SinglyListNode* newNode = new SinglyListNode(data);

    if (pListHead)
    {
        newNode->next = pListHead;
    }
    
    return newNode;
}

// Helper function to create sum list.
SinglyListNode* createSumList(SinglyListNode* pFirstListHead, SinglyListNode* pSecondListHead)
{
    SinglyListNode* pSumListHead = nullptr;
    int carry = 0;

    while (pFirstListHead || pSecondListHead)
    {
        int sum = carry;
        carry = 0;

        if (pFirstListHead)
        {
            sum += pFirstListHead->data;
            pFirstListHead = pFirstListHead->next;
        }

        if (pSecondListHead)
        {
            sum += pSecondListHead->data;
            pSecondListHead = pSecondListHead->next;
        }

        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }

        pSumListHead = insertAtFront(pSumListHead, sum);
    }

    if (carry)
    {
        pSumListHead = insertAtFront(pSumListHead, carry);
    }

    return pSumListHead;
}

// Helper function to reverse a singly linked list.
SinglyListNode* reverseList(SinglyListNode* plistHead)
{
    SinglyListNode* previousNode = nullptr;
    SinglyListNode* nextNode = nullptr;

    while (plistHead)
    {
        nextNode = plistHead->next;
        plistHead->next = previousNode;
        previousNode = plistHead;
        plistHead = nextNode;
    }

    return previousNode;
}

// Time Complexity : O(m + n) where m and n are length of the given lists.
// Extra Space : O(1)

SinglyListNode* addTwoListsWithoutExtraSpace(SinglyListNode* pFirstListHead, SinglyListNode* pSecondListHead)
{
    // Reverse the given lists
    SinglyListNode* pReversedFirstListHead = reverseList(pFirstListHead);
    SinglyListNode* pReversedSecondListHead = reverseList(pSecondListHead);

    // Create sum list
    SinglyListNode* pSumListHead = createSumList(pReversedFirstListHead, pReversedSecondListHead);

    // Reverse lists to revert back to original state.
    reverseList(pReversedFirstListHead);
    reverseList(pReversedSecondListHead);

    return pSumListHead;
}

// Time Complexity : O(m + n) where m and n are length of the given lists.
// Extra Space : O(m + n) where m and n are length of the given lists.

SinglyListNode* addTwoListsWitExtraSpace(SinglyListNode* pFirstListHead, SinglyListNode* pSecondListHead)
{
    std::stack<SinglyListNode*> firstListNodeStack;
    std::stack<SinglyListNode*> secondListNodeStack;

    // Traverse the first list and push all nodes into firstListNodeStack.
    while (pFirstListHead)
    {
        firstListNodeStack.push(pFirstListHead);
        pFirstListHead = pFirstListHead->next;
    }

    // Traverse the second list and push all nodes into secondListNodeStack.
    while (pSecondListHead)
    {
        secondListNodeStack.push(pSecondListHead);
        pSecondListHead = pSecondListHead->next;
    }

    int carry = 0;
    SinglyListNode* pSumListHead = nullptr;

    // Build the sum list.
    while ((false == firstListNodeStack.empty()) && (false == secondListNodeStack.empty()))
    {
        int sum = carry;
        carry = 0;

        sum += firstListNodeStack.top()->data + secondListNodeStack.top()->data;
        firstListNodeStack.pop();
        secondListNodeStack.pop();
       
        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }

        pSumListHead = insertAtFront(pSumListHead, sum); 
    }

    while (false == firstListNodeStack.empty())
    {
        int sum = carry;
        carry = 0;

        sum += firstListNodeStack.top()->data;
        firstListNodeStack.pop();

        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }

        pSumListHead = insertAtFront(pSumListHead, sum);
    }

    while (false == secondListNodeStack.empty())
    {
        int sum = carry;
        carry = 0;

        sum += secondListNodeStack.top()->data;
        secondListNodeStack.pop();

        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }

        pSumListHead = insertAtFront(pSumListHead, sum);
    }

    if (carry)
    {
        pSumListHead = insertAtFront(pSumListHead, carry);
    }

    return pSumListHead;
}

