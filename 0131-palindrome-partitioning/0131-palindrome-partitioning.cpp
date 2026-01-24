class Solution {
public:
bool isPalindrome(string s , int  index , int i)
{
    while(index<i)
    {
        if(s[index]!=s[i])
        return false;
        index++;
        i--;

    }

    return true;
}
    void solve(string s , vector<vector<string>>&result , vector<string>&curr , int index)
    {
        if(index==s.length())
        {
            result.push_back(curr);
            return;

        }

        if(index>s.size())
        return;

        for(int i = index ; i<s.length() ; i++)
        {
            if(isPalindrome(s , index , i))
            {
                curr.push_back(s.substr(index , i-index+1));
                solve(s , result ,curr , i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>curr;

        solve(s , result , curr , 0);

        return result;
    }
};