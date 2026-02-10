class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int n1 = nums1.size();
         int n2 = nums2.size();

         vector<int>final(n1+n2);

         double ans = 0;

         for(int i = 0 ; i<n1 ; i++)
         {
            final[i] = nums1[i];
         }
         for(int i = 0 ; i<n2 ; i++)
         {
            final[n1+i] = nums2[i];
         }

         sort(final.begin() , final.end());

         int final_size = final.size();

         int mid = final_size/2;

         if(final_size%2!=0)
         {
            ans = final[mid];
         }
         else
         {
            ans = (final[mid]+final[mid-1])/2.0;
         }


    return ans;


    }
};