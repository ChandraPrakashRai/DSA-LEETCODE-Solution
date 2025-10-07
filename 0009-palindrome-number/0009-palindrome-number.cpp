class Solution {
public:
    bool isPalindrome(int x) {
       int r, ans=0 , num=x;
       if(num<0)
       return false;
       while(num>0)
       {
        r=num%10;
        num=num/10;
        
        if(ans>INT_MAX/10)
        return false;
        ans=ans*10+r;
        
       } 
       if(ans==x)
       return true ;
    else
       return false;
    }
};