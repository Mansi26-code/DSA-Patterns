//brute
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, int>mp;
        ListNode* temp=headA;
        while(temp!=NULL)
        {
            mp[temp]++;
            temp=temp->next;
        }
        ListNode* tempB= headB;
        while(tempB!=NULL)
        {
            if(mp.find(tempB)!=mp.end())
            {
                return tempB;
            }
            tempB=tempB->next;
        }
        return NULL;
    }
};

//TC= O(m+n), SC =O(n)