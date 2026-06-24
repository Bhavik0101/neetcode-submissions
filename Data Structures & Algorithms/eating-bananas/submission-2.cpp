class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       long long  k=1;
        while(true){
            long long time=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]<k) time+=1;
                else {
                    if(piles[i]%k==0) time+=piles[i]/k;
                    else time+=piles[i]/k+1;
                }
            }
            if(time<=h) return k;
            k++;
        }
        return -1;
    }
};
