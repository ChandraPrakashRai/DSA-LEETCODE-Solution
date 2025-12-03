class Solution {
public:
    string toHex(int num) {

        if(num == 0) return "0";

        unsigned int n = num; // convert negative to unsigned
        string ans = "";
        string hex = "0123456789abcdef";

        while(n > 0) {
            ans.push_back(hex[n & 15]); // extract 4 bits
            n >>= 4;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
