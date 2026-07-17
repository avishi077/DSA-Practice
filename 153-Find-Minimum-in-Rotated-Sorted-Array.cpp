class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[low] < nums[high]){
                mini=min(nums[low], mini);
                low=mid+1;
            }
            else if(nums[low]<nums[mid]){
                mini=min(nums[low], mini);
                low=mid+1;
            }
            else if (nums[mid]<nums[high]){
                mini=min(nums[mid], mini);
                high=mid-1;
            }
            else if(nums[mid]==nums[low] && nums[low]>=nums[high]){
                mini=min(nums[high], mini);
                low=mid+1;
            }
        }
        return mini;
    }
};