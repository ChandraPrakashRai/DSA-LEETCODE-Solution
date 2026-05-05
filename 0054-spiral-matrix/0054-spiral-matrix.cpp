class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        int dir = 0;

        while (top <= bottom && left <= right) {

            if (dir == 0) { // left -> right
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (dir == 1) { // top -> bottom
                for (int i = top; i <= bottom; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (dir == 2) { // right -> left
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if (dir == 3) { // bottom -> top
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }

            dir = (dir + 1) % 4; // change direction
        }

        return res;
    }
};