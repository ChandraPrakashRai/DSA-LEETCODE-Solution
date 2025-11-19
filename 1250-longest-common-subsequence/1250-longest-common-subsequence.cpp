class Solution {
public:
int t[1001][1001];
int find(int n1 , int n2 , string &text1, string &text2 )
{
    if(n1==0 || n2==0)
    {
        return 0;
    }

    if(t[n1][n2]!=-1)
    return t[n1][n2];

    if(text1[n1-1]!=text2[n2-1])
    {
        return t[n1][n2] =  max(find(n1-1 , n2 , text1 , text2 ),find(n1 , n2-1 , text1 , text2 ));
    }
    else
    return t[n1][n2] = 1+find(n1-1 , n2-1 , text1 , text2 );


    
    
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        memset(t , -1 , sizeof(t));

        return find(n1 , n2 , text1 , text2 );
    }
};