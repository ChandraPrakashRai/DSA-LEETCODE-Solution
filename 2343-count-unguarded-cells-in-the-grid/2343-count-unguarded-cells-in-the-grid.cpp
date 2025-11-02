class Solution {
public:

    void checkGuarded(int row , int column , vector<vector<int>>&grid)
    {
        //up
        for(int i = row-1 ; i>=0 ; i--)
        {
            if(grid[i][column]==2 || grid[i][column]==3)
              break;

            else
            grid[i][column]=1;
        }
        //down 
        for(int i = row+1 ; i<grid.size() ; i++)
        {
            if(grid[i][column]==2 || grid[i][column]==3)
              break;

            else
            grid[i][column]=1;
        }

        //left
        for(int j = column-1 ; j>=0 ; j--)
        {
            if(grid[row][j]==2 || grid[row][j]==3)
              break;

            else
            grid[row][j]=1;
        }
        //right

        for(int j = column+1 ; j<grid[0].size() ; j++)
        {
            if(grid[row][j]==2 || grid[row][j]==3)
              break;

            else
            grid[row][j]=1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m , vector<int>(n,0));
        // guard ko 2 mark kr denge
        for(vector<int>&vec : guards)
        {
            int i = vec[0];
            int j = vec[1];

            grid[i][j]=2;
        }
        
        // walls ko 3 mark kr denge
        for(vector<int>&wall : walls)
        {
            int i = wall[0];
            int j = wall[1];

            grid[i][j]=3;
        }

        //  check kr lenge guard jaha jaha pe baitha hoga 
        // uske charo directions me 
        for(vector<int>guard : guards)
        {
            int i = guard[0];
            int j = guard[1];

            checkGuarded(i , j , grid);
        }



        int count = 0;
        for(int i = 0 ; i<grid.size() ; i++)
        {
            for(int j = 0 ; j<grid[0].size() ; j++)
            {
                if(grid[i][j]==0)
                count++;
            }
        }

        return count;
    }
};