class Solution {
public:

 bool DecimaltoBinary(int n)
 {
      vector<int>ans;
    while(n)
    {
        int rem = n%2;
        n = n/2;
        
        ans.push_back(rem);
     }
    
        reverse(ans.begin() , ans.end());
        
        bool result = true;

        for(int i =1 ; i<=ans.size()-1 ; i++)
        {
            if(ans[i-1]==ans[i])
             result = false;

        }

        return result;
 }
    bool hasAlternatingBits(int n) {
        
        return DecimaltoBinary(n);
        
    }
};