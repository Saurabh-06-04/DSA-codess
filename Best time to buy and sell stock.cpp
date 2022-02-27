class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int max_profit=0;
        int min_ele=prices[0];
        
        for(int i=0 ; i<n ; i++)
        {
            max_profit=max(max_profit,prices[i]-min_ele);
            min_ele=min(min_ele,prices[i]);
        }
        
        return max_profit;
    }
};
