class Solution {
public:
int lcs(string &s1 , string &s2 , int n1 , int n2 , int  i , int j , vector<vector<int>>& dp)
{
    if(i<0 || j<0 )
    {
        return  0;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s1[i]==s2[j])
    {
        return dp[i][j] =  1 + lcs(s1 , s2 , n1 , n2 ,i-1 , j-1 , dp);
    }
    else
    {
        return dp[i][j]= max(lcs(s1 , s2 , n1 , n2 ,i-1 , j , dp) , lcs(s1 , s2 , n1 , n2 ,i , j-1 , dp));
    }
}
    int longestPalindromeSubseq(string s) {

        string s2 = s;

        reverse(s2.begin() , s2.end());

        int n1 = s.size();
        int n2 = s2.size();

        vector<vector<int>>dp(n1 , vector<int>(n2+1 , -1));

        return lcs(s , s2 , n1 , n2 , n1-1 , n2-1 , dp); 
        
    }
};