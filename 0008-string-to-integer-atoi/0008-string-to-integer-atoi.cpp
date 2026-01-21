class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        long long ans = 0;
        int sign = 1;


        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        
        if(i<s.size() && s[i]=='-'|| s[i]=='+')
        {
            sign = (s[i]=='-')?-1:1;
            i++;
        }

        while(i<s.size() && s[i]>='0' && s[i]<='9')
        {
            int digit = s[i]-'0';
            ans = ans*10+digit;
            if(sign*ans>=INT_MAX) return INT_MAX;
            if(sign*ans<=INT_MIN) return INT_MIN;
            i++;
        }

        



        return sign*ans;

    }
};