class Solution {
public:
    void subset(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int i, int n) {
        ans.push_back(temp);  // push current subset

        for(int idx = i; idx < n; idx++) {
            // skip duplicates
            if(idx > i && nums[idx] == nums[idx-1]) continue;

            temp.push_back(nums[idx]);
            subset(nums, temp, ans, idx+1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort to group duplicates
        vector<int> temp;
        vector<vector<int>> ans;
        subset(nums, temp, ans, 0, nums.size());
        return ans;
    }
};
