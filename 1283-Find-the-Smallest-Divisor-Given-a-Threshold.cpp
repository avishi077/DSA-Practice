class Solution {
public:
    bool possible(const vector<int>& arr, int divi, int threshold){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/divi);
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums, mid, threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};