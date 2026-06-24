class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(i<n){
            while(st.find(s[i])!=st.end()){
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};
