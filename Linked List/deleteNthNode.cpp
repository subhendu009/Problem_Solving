/*
Delete xth node from a singly linked list. 
Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. 
The function returns the head of the modified linked list.

https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

*/

// Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


Node* deleteNode(Node *head,int x)
{
    // case 1: Either the list is empty
    // case 2 : x ==1, we have delete head node.
    if((nullptr != head) && (1 == x))
    {
        Node *nextNode = head->next;
        delete head;
        return nextNode;
    }
    
    Node *previousNode = nullptr;
    Node *currentNode = head;
    
    for(int index = 1; (index < x) && (nullptr != currentNode); ++index)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    
    // case 3: x = 0 or any other negative value
    // case 4: x has value greater than the length of the list
    // case 5: x has value within the length of the list
    if(previousNode && currentNode)
    {
        previousNode->next = currentNode->next;
        delete currentNode;
    }
    
    return head;
}
