class Solution {
public:

    bool canEat(vector<int>& piles, int mid , int h)
    {
        long long actual = 0;

        for(int i = 0 ; i<piles.size() ; i++)
        {
           actual+= piles[i]/mid;
           if(piles[i]%mid)
           {
            actual++;
           }
        }

        return actual<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int  left = 1;
        int right = *max_element(piles.begin() , piles.end());
        int ans  = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left )/2;


            if(canEat(piles , mid , h))
            {
                ans  = mid;
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};