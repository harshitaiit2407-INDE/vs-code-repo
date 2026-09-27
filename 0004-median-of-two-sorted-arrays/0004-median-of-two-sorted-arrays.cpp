class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int k = (m + n) / 2;

        vector<int> ind(m+n);
        int i = 0, j = 0, c = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ind[c] = nums1[i];
                i++;
                c++;
            } else {
                ind[c] = nums2[j];
                j++;
                c++;
            }
        }

        while (i != m)
            ind[c++] = nums1[i++];
        while (j != n)
            ind[c++] = nums2[j++];

        double ans;
        if ((m+n)%2 != 0)
            ans = ind[k];
        else
            ans = double(ind[k] + ind[k - 1]) / 2;

        return ans;
    }
};