class Solution {
public:
    vector<vector<int>> dp;

    bool match(int i, int j, string &s, string &p)
    {
        // base cases
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;

        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
                if(p[k] != '*') return false;
            return true;
        }

        // memo check
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        // recursive cases
        if(s[i] == p[j] || p[j] == '?')
        {
            ans = match(i-1, j-1, s, p);
        }
        else if(p[j] == '*')
        {
            ans = match(i, j-1, s, p) || match(i-1, j, s, p);
        }
        else
        {
            ans = false;
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n, vector<int>(m, -1));
        return match(n-1, m-1, s, p);
    }
};
