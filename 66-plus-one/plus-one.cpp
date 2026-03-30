class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        for(int i = n-1 ; i>= 0 ; i--)
        {
            // increase the last digit
            digits[i]++;

            //check either it become 10 or not
            if(digits[i]==10)
            {
                digits[i] = digits[i]%10;

            }
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits.insert(digits.begin() , 1);
        return digits;
    }
};