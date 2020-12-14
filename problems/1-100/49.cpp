//by mtf
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> um;
        vector<vector<string>> res;
        int count = 0;
        for(string s:strs)
        {
            string temp = s;
            sort(temp.begin(),temp.end());
            if(um.find(temp)!=um.end())
            {
                res[um[temp]].emplace_back(s);
            }
            else
            {
                res.emplace_back(vector<string>());
                res[count].emplace_back(s);
                um[temp]=count++;
            }
        }
        return res;
    }
};
