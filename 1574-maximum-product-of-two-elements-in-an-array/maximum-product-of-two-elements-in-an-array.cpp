class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // brute force

        int first = INT_MIN;
        int idx1 = 0;

        int second = INT_MIN;

        for(int i  = 0 ; i<nums.size() ; i++)
        {
            if(nums[i]> first){
            first = nums[i];
            idx1 = i;
            }
        }

        for(int i  = 0 ; i<nums.size() ; i++)
        {
            if(nums[i]> second && idx1!=i)
            second = nums[i];
        }

        return (first-1)*(second-1);
    }
};