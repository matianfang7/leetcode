//by mtf
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i =0;i<nums.size();++i)
        {
            if(i!=0&&um[target-nums[i]]!=0)
            {
                return {um[target-nums[i]]-1,i};
            }
            um[nums[i]]=i+1;
        }
        return {0,0};
    }
};
