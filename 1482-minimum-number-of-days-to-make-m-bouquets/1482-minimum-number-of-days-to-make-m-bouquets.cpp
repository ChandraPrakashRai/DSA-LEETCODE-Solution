class Solution {
public:
    bool canMakeBouq(vector<int>& bloomDay , int mid , int k , int m)
    {
         int consec_day = 0;
         int bouquet = 0;

         for(int i= 0 ; i<bloomDay.size() ; i++)
         {
            if(bloomDay[i]<=mid)
            {
                consec_day++;
                if(consec_day==k)
                {
                    bouquet++;
                    consec_day=0;
                }

            }
            else
            consec_day = 0;

         }

         return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int start = *min_element(bloomDay.begin(), bloomDay.end());
         int end = *max_element(bloomDay.begin() , bloomDay.end());
        int ans = -1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(canMakeBouq(bloomDay , mid , k ,  m))
            {
                ans = mid;
                end = mid-1;
            }
            else 
            start = mid + 1;

        }

        return ans;
    }
};