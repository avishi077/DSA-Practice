class Solution {
public:
    void combo(vector<int>& candidates, int target, vector<int>& current, int i, int sum, vector<vector<int>>& ans){
        if(i>=candidates.size()){
            return;
        }
        current.push_back(candidates[i]);
        if(sum+candidates[i]==target){
            ans.push_back(current);
        }
        else if(sum + candidates[i] < target) {
            combo(candidates, target, current, i,
                  sum + candidates[i], ans);
        }
        current.pop_back();
        combo(candidates, target, current, i+1, sum, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        int sum=0;

        combo(candidates, target, current, 0, 0, ans);

        return ans;
    }
};