/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
Note: Expected time complexity is O(m + n) where m and n are lengths of two linked lists.

Geeksforgeeks: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

https://www.youtube.com/watch?v=gE0GopCq378&list=PL2_aWCzGMAwLPEZrZIcNEq9ukGWPfLT4A&index=14

Leetcode : https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

#include <unordered_set>

// Linked List Node
struct Node 
{
  int data;
  struct Node *next;
  
  Node(int x) 
  {
    data = x;
    next = NULL;
  }
};


// Should return data of intersection point of two linked lists head1 and head2.
// If there is no intersecting point, then return -1.

// Time Complexity : O(m + n), where m and n are length of the lists.
// Extra Space : O(m) where m is the length of the first list.
int intersectPoint(Node* head1, Node* head2)
{
    std::unordered_set<Node *> nodeTable;
    
    while(nullptr != head1)
    {
        nodeTable.insert(head1);
        head1 = head1->next;
    }
    
    while(nullptr != head2)
    {
        if(nodeTable.find(head2) != nodeTable.end())
        {
            return head2->data;
        }
        
        head2 = head2->next;
    }
    
    return -1;
}


// Implementation without using extra space.
// Helper function to calculate length of the list.
int getListLength(Node *head)
{
	int length = 0;
	while(head)
	{
		head = head->next;
		++length;
	}

	return length;
}

// Time Complexity : O(m + n), where m and n are length of the lists. Worse total time taken than the previous one as we are traversing both lists twice.
// Extra Space : O(1)
int intersectPoint(Node *firstList, Node* secondList)
{
	int firstListLength = getListLength(firstList);
	int secondListLength = getListLength(secondList);
	
	int lenDifference = 0;
	if(firstListLength > secondListLength)
	{
		lenDifference = firstListLength - secondListLength;
	}
	else
	{
	    lenDifference = secondListLength - firstListLength;
	    std::swap(firstList, secondList);
	}

	for(int i = 0; i < lenDifference; ++i)
	{
		firstList = firstList->next;
	}

	while(firstList)
	{
		if(firstList == secondList)
		{
			return firstList->data;
		}

		firstList = firstList->next;
		secondList = secondList->next;
	}

	return -1;
}

