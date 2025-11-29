class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int i : nums)
        {
            sum = sum + i;
        }

        return sum%k;
    }
};