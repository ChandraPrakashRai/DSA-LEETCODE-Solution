class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        vector<int>arr1;
        vector<int>arr2;

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i]==0)
            {
                arr2.push_back(nums[i]);
            }
            else
            {
                arr1.push_back(nums[i]);
            }
        }

        vector<int>res(arr1.size() + arr2.size());
        
       int n1 = arr1.size();
       int i = 0;
       while(i<n1)
       {
        res[i]=arr1[i];
        i++;
       }

        int n2 = arr2.size();
       int j = 0;
       while(j<n2)
       {
        res[i+j]=arr2[j];
        j++;
       }

      for(int i = 0 ; i<res.size() ; i++)
      {
        nums[i] = res[i];
      }

    }
};