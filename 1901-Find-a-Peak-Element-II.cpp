class Solution {
public:
    int findMaxElementCol(vector<vector<int>>& mat, int m, int n, int col){
        int maxi=-1;
        int ind=-1;
        for(int i=0;i<m;i++){
            if (mat[i][col]>maxi){
                maxi=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            int row=findMaxElementCol(mat, m, n, mid);
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1<n ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row, mid};
            }
            else if(mat[row][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1, -1};
    }
};