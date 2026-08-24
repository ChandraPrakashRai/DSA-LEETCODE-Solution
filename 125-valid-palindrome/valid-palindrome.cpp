class Solution {
public:
    bool isPalindrome(string s) {
        // Convert entire string to lowercase
        for (char &c : s) {
            c = tolower(c);
        }

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
            } else if (!isalnum(s[end])) {
                end--;
            } else {
                if (s[start] != s[end]) {
                    return false;
                }
                start++;
                end--;
            }
        }

        return true;
    }
};
