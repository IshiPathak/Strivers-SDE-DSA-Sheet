class Solution {
private:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
        if(nums1[ind1] > nums2[ind2]){
            swap(nums1[ind1],nums2[ind2]);
        }
    }
public:

    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int len = (n+m);
        int gap = (len/2)+(len%2);
        while(gap>0){
            int left = 0;
            int right = left+gap;
            while(right<len){
                //arr1 and arr2
                if(left<n && right>=n){
                    swapIfGreater(nums1,nums2,left,right-n);
                }
                //arr2 and arr2
                else if(left>=n){
                    swapIfGreater(nums2,nums2,left-n,right-n);
                }
                //arr1 and arr1
                else{
                    swapIfGreater(nums1,nums1,left,right);
                }
                left++,right++;
            }
            if(gap==1) break;
            gap = (gap/2)+(gap%2);
        }
         // Copy nums2 into the vacant positions of nums1
        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};
