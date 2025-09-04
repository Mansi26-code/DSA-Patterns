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
    int findLengthOfLoop(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return 0;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;

            if(slow==fast)
            {
                ListNode*p=head;
                while(p!=slow)
                {
                    p=p->next;
                    slow=slow->next;
                }
                //when slow==p
                ListNode* start=slow->next;
                int count=1;
                while(start!=slow)
                {
                    start=start->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
    }
};

//TC= O(n)
//SC=O(1)