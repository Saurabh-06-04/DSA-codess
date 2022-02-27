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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *temp3=NULL;
        ListNode *temp4=NULL;
        int carry=0;
        
        while(temp1!=NULL || temp2!=NULL)
        {
            int sum=0;
            if(temp1!=NULL)
            {
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL)
            {
                sum+=temp2->val;
                temp2=temp2->next;
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
            //res=res->next;
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
        
        return temp3;
    }
};
