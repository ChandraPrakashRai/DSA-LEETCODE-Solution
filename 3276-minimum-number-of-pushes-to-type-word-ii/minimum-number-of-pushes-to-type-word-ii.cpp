class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }

        // sort descending
        sort(freq.begin(), freq.end(), greater<int>());

        int pushes = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            

            int cost = (i / 8) + 1;   // group logic
            pushes += freq[i] * cost;
        }

        return pushes;
    }
};