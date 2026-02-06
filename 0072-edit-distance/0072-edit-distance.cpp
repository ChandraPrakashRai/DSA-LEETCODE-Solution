class Solution {
public:
    int editDist(string s1 , string s2 , int n1 , int n2 , int i , int j , vector<vector<int>>&dp)
    {
        // base case
        if(i<0)
        {
            return  j+1;
        }
        if(j<0)
        {
            return   i+1;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j])
        {
            return dp[i][j]= editDist(s1 , s2 , n1 , n2 , i-1 , j-1 , dp);
        }
        else
        {
         return  dp[i][j] = 1+  min(
            {
            editDist(s1 , s2 , n1 , n2 ,i-1 , j ,dp) ,// delete
            editDist(s1 , s2 , n1 , n2 ,i , j-1 , dp),  //insert
            editDist(s1 , s2 , n1 , n2 ,i-1 , j-1 , dp)  // replace
             });
        }
    }
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();

        if(n1==0 && n2==0)
        return 0;

        if(n1 && !n2)
        return n1;

        if(n2 && !n1)
        return n2;


        vector<vector<int>>dp(n1, vector<int>(n2 , -1));

        return editDist(word1 , word2 , n1 , n2 , n1-1 , n2-1 , dp);

    }
};