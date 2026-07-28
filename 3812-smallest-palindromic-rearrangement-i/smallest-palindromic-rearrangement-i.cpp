class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        // Step 2: Build half of the palindrome
        string half = "";
        char middle = 0;
        
        for (int i = 0; i < 26; i++) {
            // If odd frequency, one char goes to middle
            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
            half.append(freq[i] / 2, 'a' + i);
        }
        
        // Step 3: Construct palindrome
        string result = half;
        if (middle) result.push_back(middle);
        reverse(half.begin(), half.end());
        result += half;
        
        return result;
          
    }
};