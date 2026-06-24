class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int profit=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            profit=prices[i]-mini;
            ans=max(ans,profit);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};
