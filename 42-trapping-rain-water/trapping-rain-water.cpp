class Solution {
public:
    int trap(vector<int>& height) {
        // two pointer approach

        int n = height.size();

        int water = 0;

         int left = 0;
         int right = n-1;


          int leftMax = 0;
          int rightMax = 0;

       while(left < right)
        {

            leftMax = max(leftMax , height[left]);
            rightMax = max(rightMax , height[right]);


          if(leftMax < rightMax)
          {
            water = water + leftMax - height[left];
            left++;


          }
          else
          {
           water = water + rightMax- height[right];
            right--;

          }

          
        }

        return water;
    }
};