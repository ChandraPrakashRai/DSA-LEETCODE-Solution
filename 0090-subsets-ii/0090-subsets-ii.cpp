class Solution {
public:


    void solve(vector<vector<int>>& result , vector<int>curr , vector<int> nums , int index)
    {
        if(index==nums.size())
        {
            result.push_back(curr);
            return;
        }
         result.push_back(curr);

         for(int i = index ; i<nums.size() ; i++)
             {
                if(i>index && nums[i]==nums[i-1])
                continue;  // skip

                curr.push_back(nums[i]);
                solve(result , curr , nums, i+1);
                curr.pop_back();


             }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr ;
        sort(nums.begin() , nums.end());
        solve(result , curr , nums , 0);
        return result;
    }
};