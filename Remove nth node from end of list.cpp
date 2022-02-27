/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *temp=head;
        if(head==NULL)
        {
            return temp;
        }
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        
        int pos=size-n+1;
        int count=0;
        
        
        
        if(pos==1)
        {
            return head->next;
        }
        else
        {
            ListNode *temp2=head;
            ListNode *prv=NULL;
            while(temp2!=NULL && count<pos-1)
            {
                count++;
                prv=temp2;
                temp2=temp2->next;
            }
            
            prv->next=temp2->next;
            return head;
        }
    }
};
