class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return compute(expression, memo);
    }

private:
    vector<int> compute(string expr, unordered_map<string, vector<int>>& memo) {
        if (memo.count(expr)) return memo[expr];
        vector<int> results;
        for (int i = 0; i < expr.size(); i++) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = compute(expr.substr(0, i), memo);
                vector<int> right = compute(expr.substr(i + 1), memo);
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') results.push_back(a + b);
                        else if (c == '-') results.push_back(a - b);
                        else results.push_back(a * b);
                    }
                }
            }
        }
        if (results.empty()) results.push_back(stoi(expr));
        return memo[expr] = results;
    }
};