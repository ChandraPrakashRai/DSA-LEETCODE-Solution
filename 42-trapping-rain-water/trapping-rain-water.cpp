class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        // using prefix and suffix 
        vector<int>prefix;
        vector<int>suffix;

        int water = 0;

        int left = INT_MIN;
        int right = INT_MIN;
        for(int i = 0 ; i<height.size()  ; i++)
        {
            left = max(left , height[i]);
            prefix.push_back(left);
        }
        for(int i =height.size()-1 ; i>=0  ; i--)
        {
            right = max(right , height[i]);
            suffix.push_back(right);
        }

        reverse(suffix.begin() , suffix.end());

        for(int i = 0; i<height.size() ; i++)
        {
            water += min(prefix[i] , suffix[i])-height[i];
        }

        return water;

    }
};