class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        while (i>=0 && j>=0) {
            if (nums1[i] < nums2[j]) {
                nums1[i+j+1] = nums2[j];
                j--;
            }
            else {
                nums1[i+j+1] = nums1[i];
                i--;
            }
        }
        for (int k=i;k>=0;k--) {
            nums1[k+j+1] = nums1[k];
        }
        for (int k=j;k>=0;k--) {
            nums1[i+k+1] = nums2[k];
        }
    }
};