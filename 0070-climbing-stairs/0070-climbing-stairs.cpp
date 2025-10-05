class Solution {
public:
    int climbStairs(int n) {
        // BOTTOM UP APPROACH

        if(n==1 || n==2 || n==3) return n;

        vector<int> t(n+1); // n+1 size ka ak vector bna liya hai hmne
        
        t[0]=0; 
        t[1]=1; 
        t[2]=2; 

        for(int i = 3 ; i<=n ; i++)
        {
            t[i] = t[i-1] + t[i-2];
        }

        return t[n];
    }
};