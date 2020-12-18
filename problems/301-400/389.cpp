//by mtf 
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i = 0;
        while(i<s.size())
        {
            if(s[i]!=t[i])
            {
                return t[i];
            }
            ++i;
        }
        return t[i];
    }
};

//leetcode solution
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vec(26,0);
        for(char ch : s)
        {
            vec[ch-'a']++;
        }
        for(char ch:t)
        {
            vec[ch-'a']--;
            if(vec[ch-'a']<0)
            {
                return ch;
            }
        }
        return ' ';
    }
};
