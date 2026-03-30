class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1_idx = num1.size()-1;
        int num2_idx = num2.size()-1;

        int carry = 0;

        string res;

        while(num1_idx >= 0 || num2_idx >=0 || carry > 0)
        {
           if(num1_idx >= 0)
           {
             carry += num1[num1_idx] - '0';
            num1_idx--;
           }
           if(num2_idx >= 0)
           {
             carry += num2[num2_idx] - '0';
            num2_idx--;
           }

           res.push_back((carry)%10 + '0');
           carry = carry/10;
        }

        reverse(res.begin() , res.end());

        return res;
    }
};