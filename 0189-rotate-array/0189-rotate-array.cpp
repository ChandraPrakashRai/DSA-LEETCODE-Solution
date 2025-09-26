class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin() , nums.end());

        k = k%nums.size();
            int start = 0 ;
            int end = k-1;
            
            while(start<end)
            {
                swap(nums[start] , nums[end]);
                 start++ , end--;
            }
        

       
             start = k ;
             end = nums.size()-1;
            
            while(start<=end)
            {
                swap(nums[start] , nums[end]);
                 start++ , end--;
            }
        
    }
};