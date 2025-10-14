class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // find no of rows
        int m = matrix.size();
        
        //  find number of columns

        int n = matrix[0].size();

        /*
        total 4 direction me hm ise break kr lenge for easy access 
                   1 --------------> 
                                   |
                                   |
                4                  |2
                                   |
                                   |
                   <---------------|
                           3        
        */

        //  answer vector to store result
        vector<int>ans;

        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        //  dir 1 
        // top const but left vary
        while(left<=right && top<=down)
        {
            
            for(int i = left ; i<=right ; i++)
            {
                    ans.push_back(matrix[top][i]);
            }
            top++;
            
            //  dir 2
            // top vary but right

            for(int i = top ; i<=down ; i++)
            {
                    ans.push_back(matrix[i][right]);
            }
            right--;
            //  dir 3
            // down const but right vary
            if(top<=down)
            {
                for(int i = right ; i>=left ; i--)
                {
                        ans.push_back(matrix[down][i]);
                }
                down--;
            }
            //  dir 4 
            // left const but down vary

             if(left<=right)
             {
                       for(int i = down ; i>=top ; i--)
                    {
                            ans.push_back(matrix[i][left]);
                    }
                    left++;
             }

        }

        return ans;
        
    }
};