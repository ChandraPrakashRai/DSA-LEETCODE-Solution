class Solution {
public:
    bool search(vector<int>& nums, int target) {
           int n = nums.size();
        int start = 0;
        int end = n-1;
       
        while(start <= end )
        {
            int mid = start + (end - start )/2;

            if(nums[mid]==target)
            return true;

                // 🔴 Duplicate handling (ONLY difference from version 1)
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }

            if(nums[start] <= nums[mid])   // left half sorted
             {
                if(nums[start]<=target && target<=nums[mid])
                {
                    end = mid-1;  // eliminate the right half
                }
                else
                  start = mid + 1;
             }

             else
                {
                    if(nums[mid]<=target && target <= nums[end])
                    {
                        start = mid + 1;

                    }

                    else
                     end = mid -1 ;

                }

        }



        return false;
    }
};