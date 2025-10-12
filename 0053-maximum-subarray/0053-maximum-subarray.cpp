class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //   KADANE's ALGORITHM

        
        int maxm = INT_MIN;
        int sum = 0;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            sum = sum+nums[i];

            if(sum>maxm)
            {
                maxm = sum;
            }

            if(sum < 0)
            {
                sum = 0;

            }
        }
        return maxm;
    }
};