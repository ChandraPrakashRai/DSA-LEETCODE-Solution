class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>zero;
        vector<int>one;
        vector<int>two;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i]==0)
            zero.push_back(0);
            else if(nums[i]==1)
            one.push_back(1);

            else
            two.push_back(2);
        }
        vector<int>res;

        for(int i = 0 ; i <zero.size() ; i++)
        {
            res.push_back(zero[i]);
        }
        for(int i = 0 ; i <one.size() ; i++)
        {
            res.push_back(one[i]);
        }
        for(int i = 0 ; i <two.size() ; i++)
        {
            res.push_back(two[i]);
        }

        for(int i = 0 ; i<res.size() ; i++)
        {
            nums[i] = res[i];
        }

    }
};