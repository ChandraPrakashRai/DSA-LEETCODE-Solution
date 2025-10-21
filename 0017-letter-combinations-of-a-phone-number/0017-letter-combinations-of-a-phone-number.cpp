class Solution {
public:
       vector<string> result;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        string current;
        backtrack(digits, 0, current, mp);
        return result;
    }

    void backtrack(const string& digits, int index, string& current, unordered_map<char, string>& mp) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        for (char ch : mp[digits[index]]) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, mp);
            current.pop_back(); // backtrack
        }
    }
};
