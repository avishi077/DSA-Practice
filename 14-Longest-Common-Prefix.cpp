class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s="";
        bool stop=false;
        int n=strs.size();
        if(n==1) return strs[0];
        for(int i=0;i<strs[0].size() && !stop;i++){
            for(int j=1; j<n; j++){
                if(strs[j][i]!=strs[0][i]){
                    stop=true;
                    break;
                }
            }
            if (!stop) {
                s = strs[0].substr(0, i + 1);
            }
        }
        return s;
    }
};