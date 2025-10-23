class Solution {
public:

    void solve(vector<int>& nums , int idx , vector<vector<int>>
    &result )
    {
        if(idx ==nums.size())
        {
            result.push_back(nums);
            return;
        }

       
           for( int i = idx ; i< nums.size() ; i++)
           {
             swap(nums[idx] , nums[i]);
             solve(nums , idx+1 , result);
             swap(nums[idx] , nums[i]);


           }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>>result;
        solve(nums , idx , result );

        return result;
    }
};