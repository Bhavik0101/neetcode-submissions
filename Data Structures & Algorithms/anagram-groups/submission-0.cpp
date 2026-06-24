class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<string> temp;
        vector<vector<string>> ans;
        vector<bool> grouped(n, false);
        sort(strs.begin(),strs.end());
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            if (!grouped[i]) {
                temp.push_back(strs[i]);
                grouped[i] = true;
                for (int j = 0; j < strs[i].size(); j++) {
                    mpp[strs[i][j]]++;
                }
                unordered_map<char, int> mpp1 = mpp;
                for (int j = i + 1; j < n; j++) {
                if (!grouped[j]&&strs[i].size()==strs[j].size()){
                    unordered_map<char, int> mpp1 = mpp;
                    string a = strs[j];
                    for (char c : a) {
                        mpp1[c]--;
                        if (mpp1[c] == 0)
                            mpp1.erase(c);
                    }
                    if (mpp1.size() == 0) {
                        temp.push_back(a);
                        grouped[j] = true;
                    }
                }
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};