class Solution {
public:
    int alternateDigitSum(int n) {
        int x,sum=0;
        vector<int> v1;
        while(n>0){
            v1.insert(v1.begin(), n%10);
            n=n/10;
        }
        x=v1.size();
        for(int i=0; i<x; i++) {
            if(i%2==0){
                sum=sum+v1[i];
            }
            else{
                sum=sum-v1[i];
            }
        }
        return sum;
    }
};