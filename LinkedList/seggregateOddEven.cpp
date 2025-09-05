class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(head==NULL || head->next==NULL)
       return head;

       ListNode* odd=head;
       ListNode* even=head->next;
       ListNode* evenStart= head->next;
       while(even!=NULL && even->next!=NULL)
       {
        odd->next=even->next;
       
        even->next=even->next->next;
         odd=odd->next;
        even=even->next;
       }
       odd->next=evenStart;
       return head;
    }
};

//tc=o(n)
//sc=o(1)