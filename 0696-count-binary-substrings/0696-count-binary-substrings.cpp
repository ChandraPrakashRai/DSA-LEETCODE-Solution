class Solution {
public:
    int countBinarySubstrings(string s) {
         int ans = 0;
        int prevGroup = 0;   // length of previous group
        int currGroup = 1;   // length of current group (start with 1 for first char)

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                // same group, increase count
                currGroup++;
            } else {
                // group changes, add min(prev, curr)
                ans += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        // final addition for last group
        ans += min(prevGroup, currGroup);
        return ans;

    }
};