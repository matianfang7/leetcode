//greedy
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        //从右到左扫描字符串数组，如发现左边数字大于右边，则将左边数字-1，右边所有数字变为9
        if(N<10)
        {
            return N;
        }
        string str = to_string(N);
        int n = str.size();
        for(int i=n-1;i>0;--i)
        {
            if(str[i-1]>str[i])
            {
                str[i-1]--;
                for(int j=i;j<n;++j)
                {
                    str[j]='9';
                }
            }
        }
        return stoi(str);
    }
};

//leetcode solution
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        while (i < strN.length() && strN[i - 1] <= strN[i]) {
            i += 1;
        }
        if (i < strN.length()) {
            while (i > 0 && strN[i - 1] > strN[i]) {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for (i += 1; i < strN.length(); ++i) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};
