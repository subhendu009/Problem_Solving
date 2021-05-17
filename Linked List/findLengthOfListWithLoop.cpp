/*
Q. How to find the number of nodes in linked list having a loop in it.  
Ans. https://crackinterviewtoday.wordpress.com/2010/03/17/calculate-length-of-the-linked-list-that-contains-loop/
*/

// Time Complexity : O(n) where n is the length of the list.
// Extra Space : O(1)
int getLengthOfList(Node *head)
{
	int length = 0;
	Node *fastPtr = head;
	Node *slowPtr = head;
	
	// Use slow pointer and fast pointer method to identify 
	// if loop is present or not.

	while(fastPtr && fastPtr->next)
	{
		++length;
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;

		if(slowPtr == fastPtr)
		{
			break;
		}
	}

    // if list is empty or a loop is not present, return twice the length 
    // calculated till this point.
	if(fastPtr == nullptr)
	{
		return (length * 2);		
	}

    // If loop is not present and fast pointer has reached the last node of 
    // the list, return (2 * length + 1).
	if(fastPtr->next == nullptr)
	{
		return (length * 2 + 1);
	}

    // If the list is not empty and the loop starts from the head Node
    // return length calculated so far.
	if(head == fastPtr)
	{
		return length;
	}

	length = 1;

	// Find length of the loop
	Node *meetingNode = fastPtr;
	while(fastPtr->next != meetingNode)
	{
		++length;
		fastPtr = fastPtr->next;
	}

    // Find length of non-loop portion of the list.
	while(head != slowPtr)
	{
		head = head->next;
		slowPtr = slowPtr->next;
		++length;
	}

	return length;
}
