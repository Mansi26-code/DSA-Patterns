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
int giveLen(ListNode* head)
{
    ListNode* temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int L=giveLen(head);
      if(L==n)
      {
        //mtlb head ko hi delete krdo
        ListNode* temp=head->next;
        delete(head);
        return temp;
      }

      int to_Travel=L-n;
      ListNode* prev=NULL;
      ListNode* temp=head;
      while(to_Travel--)
      {
        prev=temp;
        temp=temp->next;
      }
      prev->next=temp->next;
      delete(temp);
      return head;

    }
};

//TC=O(L)
//SC=O(1)