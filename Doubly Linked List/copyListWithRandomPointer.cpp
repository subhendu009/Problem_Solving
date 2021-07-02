/*
138. Copy List with Random Pointer.

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

Links:
Leetcode : https://leetcode.com/problems/copy-list-with-random-pointer/
Geeksforgeeks : https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/?ref=rp
                https://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/?ref=rp
                https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
                
*/

// Definition for a Node.
struct Node 
{
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


// Time Complexity : O(n), where n is the length of the given list.
// Extra Space : O(1), constant space

Node* copyRandomList(Node* head) 
{
    // If the list is empty, return
    if(nullptr == head)
    {
       return nullptr; 
    }

    Node *currentNode = head;
    // Add cloned nodes to the original list
    while(currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;
        currentNode->next = new Node(currentNode->val);
        currentNode->next->next = nextNode;
        currentNode = nextNode;
    }

    currentNode = head;

    // Adjust random pointers of newly added nodes
    while(currentNode != nullptr)
    {
        if(currentNode->random != nullptr)
        {
            currentNode->next->random = currentNode->random->next;
        }

        currentNode = currentNode->next->next;
    }

    Node *originalList = head;
    Node *clonedList = head->next;
    Node *clonedCurrentNode = clonedList;

    // Separate original list and cloned list.
    while(originalList != nullptr)
    {
        originalList->next = originalList->next->next;
        originalList = originalList->next;

        if(clonedCurrentNode->next)
        {
           clonedCurrentNode->next = clonedCurrentNode->next->next;
           clonedCurrentNode = clonedCurrentNode->next;
        }
    }

    return clonedList;
}

// Time Complexity : O(n)
// Extra Space : O(n)

Node* copyRandomList(Node* head) 
{
    std::unordered_map<Node *, Node *> nodeMap;

    Node *originalList = head;
    Node *clonedList = nullptr;
    Node *clonedListCurrentNode = nullptr;

    // Create a cloned list with only next pointer
    // Populate nodeMap hash table with original node as key and cloned node as value.
    while(originalList != nullptr)
    {
        Node *newNode = new Node(originalList->val);
        nodeMap[originalList] = newNode;

        if(nullptr == clonedList)
        {
            clonedList = newNode;
            clonedListCurrentNode = clonedList;
        }
        else
        {
            clonedListCurrentNode->next = newNode;
            clonedListCurrentNode = clonedListCurrentNode->next;
        }

        originalList = originalList->next;
    }

    clonedListCurrentNode = clonedList;

    // Update random poointers of each node of the cloned list.
    while(head != nullptr)
    {
        clonedListCurrentNode->random = nodeMap[head->random];
        clonedListCurrentNode = clonedListCurrentNode->next;
        head = head->next;
    }

    return clonedList;
}
