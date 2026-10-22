class Solution {
public:
    bool isPalindrome(string sub){
        if(sub.size()==1){
            return true;
        }
        for(int i=0;i<sub.size(); i++){
            if(sub[i]!=sub[sub.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(string &s, int start, vector<string> &current, vector<vector<string>> &result){
        if(start==s.size()){
            result.push_back(current);
            return;
        }
        for(int i=start;i<s.size();i++){
            string sub=s.substr(start, i-start+1);
            if(isPalindrome(sub)){
                current.push_back(sub);
                solve(s, i+1, current, result);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> result;
        solve(s, 0, current, result);
        return result;
    }
};