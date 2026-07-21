class Solution {
public:
    bool check(vector<int>& nums) {
        int drop=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                drop++;
            }
        }
        if (drop==0){
            return true;
        }
        else if(drop==1){
            if(nums[n-1]<=nums[0]){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            return false;
        }
        }
};