class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
         if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int low = 0, high = m;
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = totalLeft - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Check if we have a valid partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                // If total number of elements is even
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }

            // Adjust the binary search range
            if (maxLeft1 > minRight2) {
                high = partition1 - 1; // Move left
            } else {
                low = partition1 + 1;  // Move right
            }
        }

        throw invalid_argument("Input arrays are not sorted");
    }
};