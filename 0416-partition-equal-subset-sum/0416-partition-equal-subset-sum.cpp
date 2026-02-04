class Solution {
public:
bool subsetSum(vector<int>& arr,  int index , int sum ,  vector<vector<int>>& dp){
      if(sum==0)
      {
          return true;
      }
      if(index<0)
      return false;
      
      if(index==0) 
      {
          
          return dp[index][sum] = (arr[index]==sum);
      }
      
      if(dp[index][sum]!=-1)
      {
          return dp[index][sum];
      }
      
      bool nottake = subsetSum(arr , index-1 , sum  , dp);
      
      bool take = false;
      if(arr[index]<=sum)
      take = subsetSum(arr , index-1 ,  sum - arr[index] , dp);
      
      
      return dp[index][sum] =  take||nottake;
  }
    bool canPartition(vector<int>& arr) {
        
         int n = arr.size();
         int sum = 0;
         for(int i = 0 ; i<n ; i++)
         {
            sum+=arr[i];
         }

         if(sum%2!=0)
         return false;



        vector<vector<int>>dp(n , vector<int>(sum+1 , -1));
        
        return subsetSum(arr , n-1 , sum/2 , dp);

    }
};