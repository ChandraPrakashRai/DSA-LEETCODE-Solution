class Solution {
public:
    string addBinary(string a, string b) {
        int a_index = a.size()-1;
        int b_index = b.size()-1;

        int carry = 0;

        string res ;

        while(a_index>=0 || b_index>=0 || carry>0)
        {
            if(a_index>=0)
            {
                carry +=a[a_index]-'0';
                a_index--;
                
            }
            if(b_index>=0)
            {
                carry +=b[b_index]-'0';
                b_index--;

            }

            res.push_back((carry)%2 +'0');
            carry = carry/2;
        }
         reverse(res.begin() , res.end());

         return res;
    }
};