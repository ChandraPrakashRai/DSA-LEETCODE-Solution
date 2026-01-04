class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        
        int sum = 0;
        for(int i =0 ; i<nums.size() ; i++)
        {
            vector<int>res;
            int a = 1;
            while(a<=nums[i])
            {
                if(nums[i]%a==0)
                 {
                    res.push_back(a);
                    if(res.size()>4) break;
                 }
                 a++;
            }
            
            if(res.size()==4)
            {
                for(int i = 0 ; i<res.size() ; i++)
                {
                    sum+=res[i];
                }
                
            }

        }

        return sum;
    }
};