class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans = 10; // for n=1
        int uniqueDigits = 9; // choices for first digit
        int availableNum = 9; // remaining digits
        while (n-- > 1 && availableNum > 0) {
            uniqueDigits *= availableNum;
            ans += uniqueDigits;
            availableNum--;
        }
        return ans;
    }
};