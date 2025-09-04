class Solution {
public:
    ListNode *findStartingPoint(ListNode *head) {
         if(head==NULL || head->next==NULL)
         return NULL;

         ListNode* fast=head;
         ListNode* slow=head;

         while(fast!=NULL && fast->next!=NULL)
         {
            fast=fast->next->next;
            slow=slow->next;

            if(slow==fast)
            {
                ListNode* p=head;
                while(p!=slow)
                {
                    p=p->next;
                    slow=slow->next;
                }
                return slow;
            }
         }
         return NULL;
    }
};

//TC=O(n)
//SC=O(1)