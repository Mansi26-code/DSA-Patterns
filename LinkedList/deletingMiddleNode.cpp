/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return NULL;
       ListNode* fast=head;
       ListNode* slow=head;
       ListNode*prev=NULL;

       while(fast!=NULL && fast->next!=NULL)
       {
        fast=fast->next->next;
         prev=slow;
        slow=slow->next;
       
       }
       ListNode* temp=prev->next;
       prev->next=prev->next->next;
       delete(temp);
       return head;


    }
};

//TC=O(n)
//SC=O(1)