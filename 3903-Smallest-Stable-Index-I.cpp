class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini;
        int maxi;
        int index;
        int diff=0;
        for(int i=0;i<nums.size();i++){
            maxi=*max_element(nums.begin(), nums.begin()+i+1);
            mini=*min_element(nums.begin()+i, nums.end());
            diff=maxi-mini;
            if(diff<=k){
                return i;
            }
        }
        return -1;
    }
};