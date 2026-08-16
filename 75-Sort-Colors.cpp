class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos=0;
        int temp=0;
        for (int i=0;i<=2;i++){
            for (int j=0;j<nums.size();j++){
                if (nums[j]==i){
                    temp=nums[pos];
                    nums[pos]=nums[j];
                    nums[j]=temp;
                    pos++;
                }
            }
        }
    }
};