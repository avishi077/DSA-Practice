class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result, vector<bool> &used){
        
        if(index>=nums.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            current.push_back(nums[i]);
            used[i]=true;
            solve(nums, index+1, current, result, used);
            used[i]=false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> current;
        vector<vector<int>> result;
        solve(nums, 0, current, result, used);
        return result;
    }
};