class Solution {
public:

      int BS2(vector<int>& nums, int target , int n)
    {
            int second = -1;
            int start = 0;
            int end = nums.size()-1 ;
            
            while(start<=end)
            {
                int mid = start + (end - start) / 2;

                if(nums[mid]==target)
                {
                    second = mid;
                    start = mid+1;
                }
                else if(nums[mid]<target)
                {
                    start = mid+1;
                }
                else
                end  = mid-1;
            }

            return second;

    }

    int BS(vector<int>& nums, int target , int n)
    {
            int first = -1;
            int start = 0;
            int end = nums.size()-1 ;
            
            while(start<=end)
            {
                int mid = start + (end - start) / 2;

                if(nums[mid]==target)
                {
                    first = mid;
                    end = mid-1;
                }
                else if(nums[mid]<target)
                {
                    start = mid+1;
                }
                else
                end  = mid-1;
            }
        return first;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n = nums.size();
       int first = BS(nums , target , n);
       int second = BS2(nums , target , n);
        return {first,second};
    }
};