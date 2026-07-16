class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if(target==nums[mid]){
                break;
            }
            else if(nums[mid]<nums[low]){
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(nums.size()>1 && nums[mid] == nums[low] && nums[mid] == nums[high] ){
                low++;
                high--;
            }
            else{
                if(target<=nums[mid] && target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        if(target==nums[mid]){
            return true;
        }
        return false;
    }
};