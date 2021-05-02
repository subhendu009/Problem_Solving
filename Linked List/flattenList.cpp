/*
Flattening a Linked List.

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i)  a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50.

Explanation:
The resultant linked lists has every node in a single level.
(Note: | represents the bottom pointer.)


Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |
7          22
|          |
8          50
|
30

Output: 5->7->8->10->19->20->22->30->50

Explanation:
The resultant linked lists has every node in a single level.

(Note: | represents the bottom pointer.)


Geeksforgeeks: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38
*/

// Time Complexity : O(n^2 * k) where n is the number of sub-linked lists and k is the number of nodes in each list.
// Extra Space : O(1)

// Helper method to merge two sorted linked lists.
Node* mergeLists(Node *firstList, Node *secondList)
{
    // If the first list is NULL, return the second list.
	if(!firstList)
	{
		return secondList;
	}

    // If the second list is NULL, return the first list.
	if(!secondList)
	{
		return firstList;
	}

  	// Identify the head node of the merged lists.
	Node* resList = nullptr;
	if(firstList->data <= secondList->data)
	{
		resList = firstList;
		firstList = firstList->bottom;
	}
	else
	{
		resList = secondList;
		secondList = secondList->bottom;
	}

	Node *currentNode = resList;

	while(firstList && secondList)
	{
		if(firstList->data <= secondList->data)
		{
			currentNode->bottom = firstList;
			firstList = firstList->bottom;
		}
		else
		{
			currentNode->bottom = secondList;
			secondList = secondList->bottom;
		}

		currentNode = currentNode->bottom;
	}

	if(firstList)
	{
		currentNode->bottom = firstList;
	}

	if(secondList)
	{
		currentNode->bottom = secondList;
	}

	return resList;
}

Node* flatten(Node *head)
{
	Node* flattenedList = nullptr;

	while(head)
	{
		if(flattenedList)
		{
			flattenedList = mergeLists(flattenedList, head->next);
		}
		else
		{
			flattenedList = mergeLists(head, head->next);
		}

		head = head->next;
	}

	return flattenedList;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Time Complexity : O(nk log n) where n is the number of sub-linked lists and k is the number of nodes in each list.
// Extra Space : O(n)
// Using priority queue [Min Heap]

Node* flatten(Node *head)
{
	auto comparatorFunc = [](Node *first, Node *second){return first->data > second->data;};
	std::priority_queue<Node *, std::vector<Node *>, decltype(comparatorFunc)> nodeQueue(comparatorFunc);

	while(head)
	{
		nodeQueue.push(head);
		head = head->next;
	}

	Node *resList = nullptr;
	Node *currentResListNode = nullptr;
	Node *currentNode = nullptr;

	if(!nodeQueue.empty())
	{
		currentNode = nodeQueue.top();
		resList = currentNode;
		currentResListNode = resList;
		nodeQueue.pop();

		if(currentNode->bottom)
		{
			nodeQueue.push(currentNode->bottom);
		}
	}

	while(!nodeQueue.empty())
	{
		currentNode = nodeQueue.top();
		currentResListNode->bottom = currentNode;
		currentResListNode = currentResListNode->bottom;
		nodeQueue.pop();

		if(currentNode->bottom)
		{
			nodeQueue.push(currentNode->bottom);
		}
	}

	if(currentResListNode)
	{
		currentResListNode->bottom = nullptr;
	}

	return resList;
}
