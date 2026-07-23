class Solution {
public:
    bool possible(const vector<int>& arr, int m, int gap){
        int cntBalls=1;
        int lastBasket=arr[0];
        for(int i=1;i<arr.size(); i++){
            if(arr[i]-lastBasket>=gap){
                cntBalls++;
                lastBasket=arr[i];
            }
        }
        return cntBalls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low=0;
        int high=*max_element(position.begin(), position.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(position, m, mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};