class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp=1;
        int temp1=1;
        int count=0;
        vector<int> res;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            temp1*=nums[i];
            if(nums[i]!=0)
            {
                temp*=nums[i];
            }
            
            if(nums[i]==0)
            {
                count++;
            }
        }
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]!=0)
            {
                res.push_back(temp1/nums[i]);
            }
            else if(count==1)
            {
                res.push_back(temp);
            }
            else
            {
                res.push_back(0);
            }
        }
        
        return res;
    }
};
