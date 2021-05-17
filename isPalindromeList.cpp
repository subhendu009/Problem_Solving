/*
Q. Given a singly linked list of characters, write a function that returns true if the given list is a palindrome, else false.

geeksforgeeks Link : https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
Leetcode Submission Link: https://leetcode.com/submissions/detail/349428068/

*/

struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Time Complexity : O(n) where n is the length of the list.
// Extra Space : O(n) where n is the length of the list.
bool isPalindrome(ListNode* head) 
{
    std::stack<ListNode *> nodeStack;
    ListNode *currentNode = head;

    while(currentNode)
    {
        nodeStack.push(currentNode);
        currentNode = currentNode->next;
    }
  
    int halfListLength = nodeStack.size()/2;
 
    for(int currentNodeIndex = 0; currentNodeIndex < halfListLength; ++currentNodeIndex)
    {
        if(nodeStack.top()->val != head->val)
        {
            return false;
        }

        head = head->next;
        nodeStack.pop();
    }

    return true;
}

/////////////////////////////////////// Space optimized solution ////////////////////////////////////////////////////////////////////
// Function to reverse a list
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
    
// Time Complexity : O(n) where n is the length of the list.
// Extra Space : O(1)
bool isPalindrome(ListNode* head) 
{
    bool bIsPalindromeList = true;

    // Special case : If the list is empty or has only 1 node, return true.
    if(nullptr == head || nullptr == head->next)
    {
        return bIsPalindromeList;
    }

    // Split the list in two parts
    ListNode *fastPtr = head;
    ListNode *slowPtr = head;
    ListNode *firstPartLastNode = nullptr;

    while(fastPtr && fastPtr->next)
    {
        firstPartLastNode = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // At this point, list has been split into two parts.
    // Head of first part is head and that of second part is slowPtr.
    firstPartLastNode->next = nullptr;

    // Reverse the second part
    ListNode *reversedSecondPartHead = reverseList(slowPtr);
    ListNode *currentSecondPartNode = reversedSecondPartHead;

    // Now compare the first part and reversed second part.
    // If the given list is a palindrome, value at the same position will be same.
    while(head)
    {
        if(head->val != currentSecondPartNode->val)
        {
            bIsPalindromeList = false;
            break;
        }

        head = head->next;
        currentSecondPartNode = currentSecondPartNode->next;
    }

    // Now, reverse the reversed second part to get back the original second half.
    // Connect first part and second part to make the original list.
    firstPartLastNode->next = reverseList(reversedSecondPartHead);
    return bIsPalindromeList;
}
