//dp
//状态转移方程：两种状态，dp[i][0]为第i天手中无股票的最大利润，dp[i][1]为第i天手中持有一只股票的最大利润

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=0,dp[0][1]=-prices[0];
        for(int i=1;i<n;++i)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};

//优化
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sell=0,buy=-prices[0];
        for(int i=1;i<n;++i)
        {
            tie(sell,buy)=pair(max(sell,buy+prices[i]-fee),max(buy,sell-prices[i]));
        }
        return sell;
    }
};

//greedy
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int profit=0;
        int buy=prices[0]+fee;
        for(int i=1;i<n;++i)
        {
            if(prices[i]+fee<buy)
            {
                buy=prices[i]+fee;
            }
            else if(prices[i]>buy)
            {
                profit+=prices[i]-buy;
                buy=prices[i];
            }
        }
        return profit;
    }
};
