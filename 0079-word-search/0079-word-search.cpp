class Solution {
public:
    bool solve(vector<vector<char>>& board , string word , int i , int j , int index , vector<vector<bool>>&visited)
    {
        //base case
    if(index==word.size())
    return true;

    if(i<0 || j< 0 ||i>=board.size() || j>=board[0].size() || board[i][j]!=word[index]  || visited[i][j]) 
    return false;
        //recursive case
        //check in all 4 direction
    visited[i][j] = true;
        if(solve(board , word , i-1, j , index+1 , visited)||solve(board , word , i+1 , j , index+1 , visited)||solve(board , word , i , j-1 , index+1 , visited)||solve(board , word , i , j+1 , index+1 , visited))
        return true;

        visited[i][j] = false;


        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m , 0));

        for(int i = 0 ; i<n  ;i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(board , word , i , j , 0 ,visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};