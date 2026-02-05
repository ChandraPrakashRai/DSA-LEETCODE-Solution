class Solution {
public:
int LCS(string &s1 , string &s2 , int index1 , int index2 , vector<vector<int>>& dp)
{
    // base case
    if(index1<0 || index2<0)
    return 0;

    if(dp[index1][index2]!=-1)
    return dp[index1][index2];
    
    if(s1[index1]==s2[index2])
    {
        return  dp[index1][index2] =  1 + LCS(s1 , s2 , index1-1 , index2-1 , dp);
    }
    
    else
    return  dp[index1][index2] = max(LCS(s1 , s2 , index1 , index2-1 , dp) , LCS(s1 , s2 , index1-1 , index2 , dp));
  }
    int longestCommonSubsequence(string s1, string s2) {
        
          int n1 = s1.size() ;
        int n2 = s2.size();
      vector<vector<int>>dp(n1 , vector<int>(n2 , -1));
     return LCS(s1 , s2 , n1-1 , n2-1 , dp);
    }
};