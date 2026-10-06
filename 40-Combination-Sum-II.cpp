class Solution {
public:
    void solve(vector<int> &candidates, int start, int remaining, vector<int> &current, vector<vector<int>> &result){
        sort(candidates.begin(), candidates.end());
        if(remaining==0){
            result.push_back(current);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > remaining)
                break;
            current.push_back(candidates[i]);
            solve(candidates, i+1, remaining-candidates[i], current, result);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(candidates, 0, target, current, result);
        return result;
    }
};