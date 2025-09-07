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

ListNode* mergeSort(ListNode* list1, ListNode* list2)
{
    if(!list1)
    return list2;

    if(!list2)
    return list1;

    if(list1->val<=list2->val)
    {
        list1->next=mergeSort(list1->next, list2);
        return list1;
    }

    if(list2->val<=list1->val)
    {
        list2->next=mergeSort(list1, list2->next);
        return list2;
    }
}

ListNode* middleNode(ListNode* head)
{
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* fast=head->next;  //halves zyada balanced hone ke liye aisa krte hain
    ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
    ListNode* sortList(ListNode* head) {
        if(!head || head->next==NULL)
        {
            return head;
        }

        ListNode* mid=middleNode(head);
        ListNode* rightHead=mid->next;
        mid->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(rightHead);
        return mergeSort(left,right);
    }
};



//TC= O(nlogn)
//SC= O(log n)