//sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n == 0)
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};

//hash map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int num:nums)
        {
            if(us.find(num)!=us.end())
            {
                return true;
            }
            us.insert(num);
        }
        return false;
    }
};
