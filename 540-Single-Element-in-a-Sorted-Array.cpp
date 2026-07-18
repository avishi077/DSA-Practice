class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        if(nums.size()==1){
            return nums[low];
        }
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(mid!=0 && nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[mid];
    }
};