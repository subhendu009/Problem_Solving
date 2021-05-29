/*
206. Reverse Singly Linked List.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Leetcode Link : https://leetcode.com/problems/reverse-linked-list/

https://www.youtube.com/watch?v=sYcOK51hl-A  

Reverse a link list using recursion.  
  https://www.youtube.com/watch?v=KYH83T4q6Vs  

Reverse a linked list in iterative approach using 2 pointers.  
  https://www.geeksforgeeks.org/iteratively-reverse-a-linked-list-using-only-2-pointers/ 
*/

// Linked List Node structure
struct Node
{
    int data;
    Node *next;
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

//Recursive implementation.
// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(n) where n is the length of the given list, due to recursive call stack.

Node* reverseList(Node* head)
{
	// Base Condition. Return head node if it is NULL or the last node of the list.
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	//Recursive call
	Node* reversedList = reverseList(head->next);

	// Create links
	head->next->next = head;
	head->next = nullptr;

	return reversedList;
}

//Iterative implementation.
// Time Complexity : O(n) where n is the length of the given list.
// Extra Space : O(1)

Node* reverseList(Node* head)
{
	Node* previousNode = nullptr;
	Node* nextNode = nullptr;
	Node* currentNode = head;

	while (currentNode)
	{
		nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	return previousNode;
}

