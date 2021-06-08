/*
2. Add Two Numbers.

Given two numbers represented by two lists, write a function that returns the sum list.   
The sum list is list representation of the addition of two input numbers. 

Input:
	List1: 5->6->3 // represents number 365    
	List2: 8->4->2 // represents number 248
	   
Output: 
Resultant list: 3->1->6 // represents number 613 

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
https://leetcode.com/problems/add-two-numbers/

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


ListNode* addTwoNumbers(ListNode* firstHead, ListNode* secondHead) 
{
	int carry = 0;
	ListNode *resList = nullptr;
	ListNode *currentNode = nullptr;

	while((firstHead != nullptr) || (secondHead != nullptr))
	{
		int sum = carry;
		carry = 0;

		if(firstHead != nullptr)
		{
			sum += firstHead->val;
			firstHead = firstHead->next;
		}

		if(secondHead != nullptr)
		{
			sum += secondHead->val;
			secondHead = secondHead->next;
		}
		
		if(sum > 9)
		{
			carry = 1;
			sum -= 10;
		}

		if(nullptr == resList)
		{
			resList = new ListNode(sum);
			currentNode = resList;
		}
		else
		{
			currentNode->next = new ListNode(sum);
			currentNode = currentNode->next;
		}
	}
	
	if(carry == 1)
	{
		currentNode->next = new ListNode(carry);
	}
	
	return resList;
}

