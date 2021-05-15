/*
Given two Singly Linked List of N and M nodes respectively. 
The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.
For example Linked lists a (1->2->3) and b(1->2->3) are identical.

https://www.geeksforgeeks.org/identical-linked-lists/

*/

// Structure of the node of the linked list is as
struct Node 
{
    int data;
    Node *next;
  
    Node(int x) 
    {
        data = x;
        next = NULL;
    }
};

// This function should return true if both linked lists are identical else return false.
bool areIdenticalLists(Node *firstListHead, Node *secondListHead)
{
    // Traverse both lists
    while(firstListHead && secondListHead)
    {
	    // If data in nodes are not identical, return false.
	    if(firstListHead->data != secondListHead->data)
	    {
		    return false;
	    }
	    
	    firstListHead = firstListHead->next;
	    secondListHead = secondListHead->next;
    }
    
    return (firstListHead == secondListHead);
}

