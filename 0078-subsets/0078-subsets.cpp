class Solution {
public:
        void solve(vector<int>& nums , int idx ,   vector<int>&current , vector<vector<int>>&result )
    {
        if(idx ==nums.size())
        {
            result.push_back(current);
            return;
        }

            //include
            current.push_back(nums[idx]);
             solve(nums , idx+1 ,current , result);
             current.pop_back();

            //exclude
            solve(nums,idx+1 , current , result);

           
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        vector<int>current;
        vector<vector<int>>result;

        solve(nums , idx , current , result);

        return result;
        
    }
};