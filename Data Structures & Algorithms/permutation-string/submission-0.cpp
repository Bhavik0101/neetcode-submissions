class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(char c:s1){
            mpp1[c]++;
        }
         int j=0;
         int i=s1.size();
        for(int i=0;i<s1.size();i++){
            mpp2[s2[i]]++;
        }
        while(i<s2.size()){
            if(mpp1==mpp2) return true;
            else{
                mpp2[s2[j]]--;
                if(mpp2[s2[j]]==0) mpp2.erase(s2[j]);
                mpp2[s2[i]]++;
                j++;
                i++;

            }
        }
        if(mpp1==mpp2) return true;
        return false;

    }
};