class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
        return x;

        int result = 1;
        for(long long i = 0 ; i*i<=x; i++)
        {
            result = i;

        }

        return result;
    }
};