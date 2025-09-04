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

//sc & tc= O(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
         stack<int>st; 
         ListNode* temp=head;

         while(temp!=NULL)
         {
            st.push(temp->val);
            temp=temp->next;
         }
temp=head;
         while(!st.empty())
         {
            if(st.top()!=temp->val)
            {
                return false;
                break;
            }
            st.pop();
            temp=temp->next;

         }
         return true;
    }
};

//sc=o(1), tc=O(n)
class Solution {
public:
ListNode* reverseList(ListNode* head)
{
    if(head==NULL || head->next==NULL)
    return head;
 
 ListNode* newHead=reverseList(head->next);
 head->next->next=head;
 head->next=NULL;
 return newHead;

}
    bool isPalindrome(ListNode* head) {
         if(head==NULL || head->next==NULL)
         return true;

         ListNode* slow=head;
         ListNode* fast=head;
         while(fast->next!=NULL && fast->next->next!=NULL )
         {
            fast=fast->next->next;
            slow=slow->next;
         }

         ListNode* first=head;
         ListNode* second=reverseList(slow->next);
         while(second!=NULL)
         {
            if(first->val!=second->val)
            {
                reverseList(second);
                return false;
                break;
            }
            first=first->next;
            second=second->next;
         }
          reverseList(second);
         return true;
    }
};