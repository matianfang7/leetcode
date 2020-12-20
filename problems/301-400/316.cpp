//stack+greedy
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> num(26),vis(26);
        string stk;
        for(char ch:s)
        {
            num[ch-'a']++;
        }
        for(char ch : s)
        {
            if(!vis[ch-'a'])
            {
                while(!stk.empty()&&stk.back()>ch)
                {
                    if(num[stk.back()-'a']>0)
                    {
                        vis[stk.back()-'a']=0;
                        stk.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                vis[ch-'a']=1;
                stk.push_back(ch);
            }
            num[ch-'a']--;
        }
        return stk;
    }
};
