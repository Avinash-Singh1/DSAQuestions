class Solution {
public:
    void SwapIfGreater(vector<int>& nums1, vector<int>& nums2, int left, int right) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start by copying all elements of nums2 into the end of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        int len = m + n;                    // Total length of the merged array
        int gap = (len / 2) + (len % 2);    // Initial gap

        // Continue until the gap reduces to zero
        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            // Use the gap to compare elements within the merged range
            while (right < len) {
                // Case 1: Both indices within the merged nums1 array
                if (right < m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 2: left in the original nums1, right in nums2 portion of nums1
                else if (left < m && right >= m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 3: Both indices in the copied nums2 portion of nums1
                else {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                left++;
                right++;
            }

            // Update gap for the next pass
            if (gap == 1) break; // Exit when gap reduces to 1
            gap = (gap / 2) + (gap % 2);
        }
    }
};
