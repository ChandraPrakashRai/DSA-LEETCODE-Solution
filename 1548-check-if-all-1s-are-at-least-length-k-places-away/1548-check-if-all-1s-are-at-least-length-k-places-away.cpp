class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1; // store index of previous 1

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {

                // if this is not the first 1
                if (prev != -1) {

                    // check the gap between two 1s
                    int gap = i - prev - 1;

                    if (gap < k) 
                        return false;
                }

                // update prev to current 1 position
                prev = i;
            }
        }

        return true;
    }
};
