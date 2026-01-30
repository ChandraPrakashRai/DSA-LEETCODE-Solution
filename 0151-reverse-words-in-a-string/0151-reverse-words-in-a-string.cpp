class Solution {
public:

    // Reverse string template (two pointer)
    void reverseStr(string &s, int l, int r) {
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    string reverseWords(string s) {

        int n = s.size();

        // STEP 1: Reverse the entire string
        reverseStr(s, 0, n - 1);

        int L = 0;   // start of word
        int I = 0;   // traversal pointer

        while (I < n) {

            // STEP 2: Ignore leading / extra spaces
            while (I < n && s[I] == ' ')
                I++;

            L = I;  // fix L at first character of word

            // STEP 3: Move I till space or end
            while (I < n && s[I] != ' ')
                I++;

            int R = I - 1; // end of word

            // STEP 4: Reverse current word
            if (L < n)
                reverseStr(s, L, R);

            // I is already at space, move ahead
            I++;
        }

        // STEP 5: Remove extra spaces (cleanup)
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (!ans.empty()) ans += ' ';
                while (i < n && s[i] != ' ') {
                    ans += s[i];
                    i++;
                }
            }
        }

        return ans;
    
    }
};