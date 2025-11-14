class Solution {
public:
    long long maxOperations(string s) {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // we’ve seen another '1' that could be slid later
                ones++;
            } 
            else { // s[i] == '0'
                // if this zero is at the end OR next char is '1', it triggers operations
                if (i + 1 == n || s[i + 1] == '1') {
                    ans += ones;
                }
            }
        }
        return ans;
    }
};
