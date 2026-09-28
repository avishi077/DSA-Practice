class Solution {
public:
    vector<int> current;
    vector<vector<int>> result;
    void solve(int n, int k, int start){
            if (k == 0) {
            result.push_back(current); 
            return; 
            }
            for(int i=start; i<=n; i++){
                current.push_back(i);
                solve(n, k-1,i+1);
                current.pop_back();
            } 
        }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);      
        return result;
    }
};