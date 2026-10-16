class Solution {
public:
    void solve(int start, int k, int remaining, vector<int>& current, vector<vector<int>>& result){
        if(remaining<0){
            return;
        }
        if(current.size()==k && remaining==0){
            result.push_back(current);
            return;
        }
        if(remaining==0 && current.size()!=k){
            return;
        }
        if(current.size()==k && remaining>0){
            return;
        }

        for (int i = start; i <= 9 - (k - current.size()) + 1; i++) {
            current.push_back(i);
            solve(i + 1, k, remaining - i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> result;
        solve(1, k, n, current, result);
        return result;
    }
};