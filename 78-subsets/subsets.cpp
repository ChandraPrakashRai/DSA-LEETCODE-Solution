class Solution {
public:
    void subset(vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans , int i , int n)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        subset(nums , temp , ans , i+1 , n);


        //pop back
        temp.pop_back();


        //nottake
          subset(nums , temp , ans , i+1 , n);


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;

        int n = nums.size();


        subset(nums , temp , ans , 0 , n);

        return ans;
    }
};