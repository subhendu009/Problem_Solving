/*
Reverse a Doubly Linked List.
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.
Example 1:
Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:
Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Geeksforgeeks: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#
*/

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node* reverseDoublyLinkedList(Node * head)
{
    Node *previousNode = nullptr;
    Node *nextNode = nullptr;
    
    while(head)
    {
        nextNode = head->next;
        head->next = previousNode;
        head->prev = nextNode;
        
        previousNode = head;
        head = nextNode;
    }
    
    return previousNode;
}
