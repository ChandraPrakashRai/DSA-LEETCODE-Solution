class Solution {
    public int[] runningSum(int[] nums) {
        

        // java use array as
        // int[] num   unlike of cpp int num[]

        int n = nums.length;
        nums[0] = nums[0];
        for(int i = 1 ; i<n ; i++)
        {
            nums[i] = nums[i] + nums[i-1];
        }

        return nums;
    }
}