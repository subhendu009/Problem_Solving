/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that 
checks whether a given Linked List contains a loop or not and if the loop is present then 
return the count of nodes in a loop or else return 0.

https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/  
*/

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Time Complexity : O(n) where n is the length of the list.
// Extra Space : O(1)

int countNodesinLoop(Node *head)
{
    bool bIsLoopPresent = false;
    
    // Check if the list contains loop or not.
    Node *fastPtr = head;
    Node *slowPtr = head;
    
    while((nullptr != fastPtr) && (nullptr != fastPtr->next))
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        
        if(slowPtr == fastPtr)
        {
            bIsLoopPresent = true;
            break;
        }
    }
    
    if(false == bIsLoopPresent)
    {
        return 0;
    }
    
    //Loop is present, hence count the number of nodes in the loop.
    int nodesInLoop = 1;
    
    Node *nextNode = fastPtr->next;
    while(nextNode != fastPtr)
    {
        nextNode = nextNode->next;
        ++nodesInLoop;
    }
    
    return nodesInLoop;
}
