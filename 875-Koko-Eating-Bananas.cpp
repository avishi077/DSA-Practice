class Solution {
public:
    bool isGivenSpeedOkay(const vector<int>& arr, int bananasperhour, int h){
        long long time=0;
        for(int i=0;i<arr.size(); i++){
            time+=ceil((double)arr[i]/bananasperhour);
            if (time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if(isGivenSpeedOkay(piles, mid, h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            } 
        }    
        return low;    
    }
};