class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int num = 1; // as usually array starts from number 1
        int n = nums.size();
       int i = 0;
        while(i<n && k>0)
        {
            if(nums[i]==num) // mtlb missing nhi hai
            {
                i++;
            }
            else
            {
                k--;
            }

            num++;
        }

        // man lo aisa case ho jisme kuch missing hi nhi ho tb
        while(k--)
        {
            num++;
        }
        return num-1;
    }
};