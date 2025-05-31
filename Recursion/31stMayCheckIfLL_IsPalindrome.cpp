/*
Definition of singly linked list:
This defines the basic structure of a singly linked list node.
Each node contains an integer value and a pointer to the next node.
*/
struct ListNode
{
    int val;            // Value stored in the node
    ListNode *next;     // Pointer to the next node in the list

    // Default constructor initializes value to 0 and next to NULL
    ListNode()
    {
        val = 0;
        next = NULL;
    }

    // Constructor that initializes value to data1 and next to NULL
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }

    // Constructor that initializes both value and next pointer
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    /*
    Function to check if the linked list is a palindrome.
    A palindrome is a sequence that reads the same backward as forward.
    */
    bool isPalindrome(ListNode* head) {
    
        // Step 1: Create a stack to store values of the nodes
        stack<int> st;

        // Step 2: Use a temporary pointer to traverse the list from the beginning
        ListNode* temp = head;

        // Step 3: Push each node's value into the stack
        while(temp != NULL)
        {
            st.push(temp->val);  // Store current node's value in stack
            temp = temp->next;   // Move to the next node
        }

        // Step 4: Reset temp back to head to traverse again from the start
        temp = head;

        // Step 5: Compare each node's value with the top of the stack
        while(!st.empty())
        {
            /*
            If current node's value does not match the top of the stack,
            then the list is not a palindrome, so return false
            */
            if(temp->val != st.top())
            {
                return false;
            }

            st.pop();          // Remove the top value from the stack
            temp = temp->next; // Move to the next node in the list
        }

        // Step 6: If all values matched, then the list is a palindrome
        return true;
    }
};


