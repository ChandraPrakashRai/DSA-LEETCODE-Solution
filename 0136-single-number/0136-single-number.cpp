class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // using xor
        // in xor  a ^ a = 0  , a ^ 0 = a ;
        // same pe zero 
        
        int ans = 0 ;
        for(int i = 0 ;i<nums.size() ; i++)
        {
             ans = ans^nums[i];
        }

        return ans;
    }
};