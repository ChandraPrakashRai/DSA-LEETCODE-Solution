class Solution {
public:

    void perm(vector<int>& nums, int idx,
              vector<vector<int>>& ans, int n)
    {
        // base case
        if(idx == n)
        {
            ans.push_back(nums);
            return;
        }

        set<int> used;

        for(int i = idx; i < n; i++)
        {
            // duplicate ko same level par skip karo
            if(used.count(nums[i]))
            {
                continue;
            }

            used.insert(nums[i]);

            swap(nums[i], nums[idx]);

            perm(nums, idx + 1, ans, n);

            // backtrack
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();

        perm(nums, 0, ans, n);

        return ans;
    }
};