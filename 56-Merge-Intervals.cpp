class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(intervals.begin(), intervals.end());
        if (intervals.empty()) return {};
        else{
            int start=intervals[0][0];
            int end=intervals[0][1];
            for(int i=1; i<intervals.size(); i++){
                if(intervals[i][0]<=end){
                    end=max(end, intervals[i][1]);
                }
                else{
                    temp={start, end};
                    ans.push_back(temp);  
                    start=intervals[i][0];
                    end=intervals[i][1];              
                }
            }
            temp={start, end};
            ans.push_back(temp);
            return ans;
        }
    }
};