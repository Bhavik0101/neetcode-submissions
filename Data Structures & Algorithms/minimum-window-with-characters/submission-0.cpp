class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp1;
        for (auto c : t) {
            mpp1[c]++;
        }

        int j = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {

            if (mpp1.find(s[i]) != mpp1.end()) {
                string temp = "";
                unordered_map<char, int> mpp;
                mpp = mpp1;
                j = i;
                while (j < s.size()) {
                    temp += s[j];
                    if (mpp.find(s[j]) != mpp.end()) {
                        mpp[s[j]]--;
                        if (mpp[s[j]] == 0)
                            mpp.erase(s[j]);
                    }

                    if (mpp.size() == 0) {
                        if (ans.size() == 0)
                            ans = temp;
                        if (ans.size() != 0) {
                            if (temp.size() < ans.size())
                                ans = temp;
                        }

                        break;
                    }
                    j++;
                }
                // if (mpp.size() != 0)
                //     return "";
            }
        }
     
    
        return ans;
    }
};