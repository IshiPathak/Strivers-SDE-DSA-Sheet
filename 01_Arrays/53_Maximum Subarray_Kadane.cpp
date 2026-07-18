class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ansStart = -1;
        int ansEnd = -1;
        int maxi = INT_MIN;
        int sum = 0;
        int start;
        for(int i = 0; i<nums.size(); i++){
            if(sum==0) start = i;
            sum = sum+nums[i];
            if(sum>maxi){
                maxi = sum;
                ansStart = start; ansEnd = i;
            }
            if(sum<0) sum = 0;
        }
        return maxi;
    }
};
