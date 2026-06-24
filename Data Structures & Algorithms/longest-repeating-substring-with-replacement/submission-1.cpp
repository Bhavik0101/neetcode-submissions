class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int i=0;
        int j=0;
        int ans=0;
        int n=s.size();
        
        while(i<n){
            mpp[s[i]]++;
            int maxf=0;
            for(auto&p:mpp){
                maxf=max(maxf,p.second);
            }
            int total=i-j+1;
            while(total-maxf>k){
                mpp[s[j]]--;
                if(mpp[s[j]]==0) mpp.erase(s[j]);
                total--;
                j++;
            }
            if(total-maxf<=k) ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};
