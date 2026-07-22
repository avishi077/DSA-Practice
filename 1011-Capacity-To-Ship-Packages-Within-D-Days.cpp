class Solution {
public:
    bool possible(const vector<int>& arr, int chosenCap, int givenDays){
        int load=0;
        int days=1;
        for(int i=0; i<arr.size(); i++){
            if(load+arr[i]>chosenCap){
                days++;
                load=arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return days<=givenDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if(possible(weights, mid, days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};