class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin());
        }

        return ans;
    }
};