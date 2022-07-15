class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==tar) return mid;
            else if(nums[mid]<tar) lo=mid+1;
            else hi=mid-1;
        }
        return lo;
    }
};
