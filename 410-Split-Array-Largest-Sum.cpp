class Solution {
public:
    bool possible(const vector<int>& arr, int k, int chosenLen){
        int sum=0;
        int students=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=chosenLen){
                sum+=arr[i];
            }
            else{
                students++;
                sum=arr[i];
            }
        }
        return students<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};