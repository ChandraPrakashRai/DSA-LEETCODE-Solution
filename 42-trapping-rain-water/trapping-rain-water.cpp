class Solution {
public:
    int trap(vector<int>& height) {
        // Trapping of Rain Watre ka sbse Best Way 
        // and Easy Way hai
        // Prefix (LeftMax) 
        // and Suffix(RightMax) method kahte hai

        // pREFIX(lEFTmaX)
        int n = height.size();
        vector<int>prefix(n);
        prefix[0] = height[0];

        for(int i = 1 ; i<height.size() ; i++)
        {
            prefix[i] = max(prefix[i-1] , height[i]);
        }

        vector<int>suffix(n);
        suffix[n-1] = height[n-1];

        for(int i = n-2 ; i>=0 ; i--)
        {
            suffix[i] = max(suffix[i+1] , height[i]);
        }

        int water = 0;

        for(int i = 0 ; i<n ; i++)
        {
            water = water + min(prefix[i] , suffix[i]) - height[i];
        }


        return water;
    }
};