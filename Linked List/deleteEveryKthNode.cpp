/* 
Given a singly linked list, your task is to remove every kth node from the linked list.

Example 1:
Input:
List : 1 2 3 4 5 6 7 8
K = 3

Output:
1 2 4 5 7 8

Explanation:
After removing every 3rd element from the linked list, we have updated list as 1, 2, 4, 5, 7 and 8
and the elements which are removed are 3 and 6.

Example 2:
Input:
List : 1 2 3 4
K = 2

Output:
1 3

Geeksforgeeks: https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1#
*/

// Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* deleteEveryKthNode(Node *head, int k)
{
	// Case 1: K is an invalid input. Return head.
	if(k < 1)
	{
		return head;
	}

	Node *currentNode = head;
	// Case 2: 2<= K <= length of the list.
	while(currentNode)
	{
		Node *previousNode = nullptr;
		
		// Reach Kth node
		for(int count = 1; (count < k) && currentNode; ++count)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

        	// Delete Kth node
        	// Case 3: k = 1.
		if(currentNode)
		{
			Node *nextNode = currentNode->next;
			if(previousNode)
			{
				previousNode->next = nextNode;
			}

			delete currentNode;
			currentNode = nextNode;
		}
	}

    	// Case 3: K = 1, we have already deleted the entire list. Return nullptr.
	if(k == 1)
	{
		head = nullptr;
	}

	return head;
}
