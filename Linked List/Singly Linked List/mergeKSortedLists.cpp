/*
23. Merge k Sorted Lists.

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list: 1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

Leetcode : https://leetcode.com/problems/merge-k-sorted-lists/

*/
// METHOD 1 : Without using any extra space.

// Time Complexity : O(n ^ 2 * k) where n is the number of lists and k is the number of nodes in each list. Assuming k nodes in each list.
// Extra Space : O(1)


ListNode* mergeKLists(const std::vector<ListNode*> &lists)
{
    if(lists.size() == 0)
    {
        return nullptr;
    }

    ListNode *mergedList = lists[0];

    for(int listIndex = 0; listIndex < (lists.size() - 1); ++listIndex)
    {
        mergedList = mergeTwoLists(lists[listIndex + 1], mergedList);
    }

    return mergedList;
}

// METHOD 2:
// Recursive Approach - Divide & Conquer.
// Time Complexity : O(nk log n)
// Extra Space : O(n) for recursion stack.
// where n is the number of lists and k is the number of nodes in a list.

ListNode* mergeKLists(const vector<ListNode*> &lists)
{
    if(lists.size() == 0)
    {
        return nullptr;
    }

    return mergeKListsHelper(lists, 0, lists.size() - 1);
}

ListNode* mergeKListsHelper(const vector<ListNode*> &lists, int start, int end)
{
    if(start >= end)
    {
        return lists[start];
    }

    int mid = start + (end - start)/2;

    ListNode* first = mergeKListsHelper(lists, start, mid);
    ListNode* second = mergeKListsHelper(lists, mid + 1, end);

    return mergeTwoLists(first, second);
}

// Common helper method to merge two sorted singly linked lists.
ListNode *mergeTwoLists(ListNode *firstList, ListNode *secondList)
{
    if(nullptr == firstList)
    {
        return secondList;
    }

    if(nullptr == secondList)
    {
        return firstList;
    }

    ListNode *mergedList = nullptr;

    if(firstList->val <= secondList->val)
    {
        mergedList = firstList;
        firstList = firstList->next;
    }
    else
    {
        mergedList = secondList;
        secondList = secondList->next;
    }

    ListNode *mergedListCurrentNode = mergedList;

    while(firstList && secondList)
    {

        if(firstList->val <= secondList->val)
        {
            mergedListCurrentNode->next = firstList;
            firstList = firstList->next;
        }
        else
        {
            mergedListCurrentNode->next = secondList;
            secondList = secondList->next;
        }

        mergedListCurrentNode = mergedListCurrentNode->next;
    }

    if(firstList)
    {
        mergedListCurrentNode->next = firstList;
    }
    else
    {
        mergedListCurrentNode->next = secondList;
    }

    return mergedList;
}

// METHOD 3:
// Using priority_queue (Min Heap)
// Time Complexity : O(nk log n)
// Extra Space : O(n)
// where n is the number of lists and k is the number of nodes in a list.
ListNode* mergeKLists(const vector<ListNode*> &lists)
{
    auto comareFunction = [](ListNode *firstNode, ListNode *secondNode)
    {
        return firstNode->val > secondNode->val;
    };

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comareFunction)> nodeQueue(comareFunction);

    for(auto listHead : lists)
    {
        if(listHead)
        {
            nodeQueue.push(listHead);
        }
    }

    ListNode* currentNode = nullptr;
    ListNode *mergedList = nullptr;
    ListNode *mergedListCurrentNode = nullptr;

    if(!nodeQueue.empty())
    {
        currentNode = nodeQueue.top();
        mergedList = currentNode;
        mergedListCurrentNode = mergedList;
        nodeQueue.pop();

        if(currentNode->next)
        {
            nodeQueue.push(currentNode->next);
        }
    }

    while(!nodeQueue.empty())
    {
        currentNode = nodeQueue.top();
        mergedListCurrentNode->next = currentNode;
        mergedListCurrentNode = mergedListCurrentNode->next;
        nodeQueue.pop();

        if(currentNode->next)
        {
            nodeQueue.push(currentNode->next);
        }
    }

    if(mergedListCurrentNode)
    {
        mergedListCurrentNode->next = nullptr;
    }

    return mergedList;
}
