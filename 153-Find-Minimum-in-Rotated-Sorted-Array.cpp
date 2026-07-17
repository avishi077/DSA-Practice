class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini;
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[low] <= nums[high]){
                return nums[low];
            }
            else if(nums[mid]==nums[low] && nums[low]>nums[high]){
                return nums[high];
            }
            else if (nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if (nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]<nums[high]){
                high=mid-1;
            }
        }
        return nums[mid];
    }
};