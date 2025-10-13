class Solution {
public:
    int trap(vector<int>& height) {
            int n = height.size();

        vector<int>leftMax(n);
        vector<int>rightMax(n);
         leftMax[0] = height[0];
        for(int i= 1 ; i<height.size() ; i++ )
        {
           leftMax[i]=max(leftMax[i-1] , height[i]);
        }

         rightMax[n-1] = height[n-1];
        for(int i= height.size()-2 ; i>=0; i-- )
        {
           rightMax[i]=max(rightMax[i+1] , height[i]);


        }

        vector<int>water;
        for(int  i=0 ; i< height.size() ; i++){
            int w_i = min(leftMax[i] , rightMax[i]) - height[i];
            water.push_back(w_i);
        }

        int sum = 0;
        for(int i =0 ; i< water.size() ; i++ )
        {
            sum = sum + water[i];
        }

        return sum;


    }
};