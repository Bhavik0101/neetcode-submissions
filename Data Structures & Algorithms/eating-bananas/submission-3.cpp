class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mid;
        int ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            long long time=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]<=mid) time+=1;
                else{
                    if(piles[i]%mid==0) time+=piles[i]/mid;
                    else time+=piles[i]/mid+1;
                }
            }
            if(time<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
