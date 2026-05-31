class Solution {
public:
    int maxArea(vector<int>& height) {
        

        int maxWater = 0;
        int lh = 0;
        int rh = height.size()-1;

        while(lh < rh)
        {
            int w = rh - lh;
            int ht = min(height[lh] , height[rh]);

            int currWater = ht * w;

            maxWater = max(maxWater , currWater);

            if(height[lh] < height[rh])
            {
                lh++;
            }
            else
            rh--;
        }

        return maxWater ;
    }
};