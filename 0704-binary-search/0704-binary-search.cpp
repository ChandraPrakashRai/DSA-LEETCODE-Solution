class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int start = 0;
        int end = n-1;

        while(start<=end)
        {
        int mid = (start+end )/ 2;

            if(target == arr[mid])
            {
                return mid;
            }

            else if(target < arr[mid])
            {
                end = mid - 1;

            }
            else
            {
                start = mid+1;
            }

        }

        return -1;

    }
};