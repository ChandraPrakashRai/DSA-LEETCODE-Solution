class Solution {
public:
    void solve(vector<string>& result , string curr , int n , int open , int close)
    {
        if(curr.size()==2*n)
        {
            result.push_back(curr);
            return;
        }

        if(open<n)
        {
            curr.push_back('(');
            solve(result , curr , n , open+1 , close);
            curr.pop_back();
        }
        if(close<open)
        {
            curr.push_back(')');
            solve(result , curr , n , open , close+1);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int open = 0 ;
        int close = 0;

        vector<string>result;

        string curr = "";

        solve(result ,curr , n , open , close);

        return result;
    }
};