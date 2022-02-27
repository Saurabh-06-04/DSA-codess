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
    ListNode* reverse(ListNode* l)
    {
        ListNode* temp=NULL;
        ListNode* curr=l;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            temp=curr;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        
        l=prev;
        
        return l;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0;
        int len2=0;
        
        ListNode* res;
        ListNode* t_head1=reverse(l1);
        ListNode* t_head2=reverse(l2);
        ListNode* temp3=NULL;
        ListNode *temp4=NULL;
        
        int carry=0;
        
        while(t_head1!=NULL || t_head2!=NULL)
        {
            int sum=0;
            if(t_head1!=NULL)
            {
                sum+=t_head1->val;
                t_head1=t_head1->next;
            }
            
            if(t_head2!=NULL)
            {
                sum+=t_head2->val;
                t_head2=t_head2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            res=new ListNode(sum%10);
            
            if(temp3==NULL)
            {
                temp3=res;
            }
            else
            {
                temp4=temp3;
                while(temp4->next!=NULL)
                {
                    temp4=temp4->next;
                }
                temp4->next=res;
                temp4=res;
            }
        }
        if(carry!=0)
        {
            res=new ListNode(carry);
            temp4=temp3;
            while(temp4->next!=NULL)
            {
                temp4=temp4->next;
            }
            temp4->next=res;
        }
        
        ListNode* final_call=reverse(temp3);
        
        return final_call;
    }
};
