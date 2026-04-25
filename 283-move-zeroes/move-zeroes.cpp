class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // optimized code 

        // use two pointer approach

        int left = 0 ;
        int right = 0;


        for(int i = 0 ; i<nums.size() ; i++)
        {

            if(nums[right]!=0)
            {
                swap(nums[left] , nums[right]);
                right++;
                left++;
            }
            else
            right++;

        }
    }
};