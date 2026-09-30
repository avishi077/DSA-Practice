class Solution {
public:
    void solve(string s, int index, string &current, vector<string> &result){
        if(index==s.size()){
            result.push_back(current);
            return;
        }
        char ch = s[index];
        if(ch>=48 && ch<=57){
            current.push_back(ch);
            solve(s, index + 1, current, result);
            current.pop_back();
        }
        else{
            current.push_back(ch);
            solve(s, index+1, current, result);
            current.pop_back(); 
            
            current.push_back(ch^32);
            solve(s, index+1, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string current;
        vector<string> result;
        solve(s, 0, current, result);
        return result;
    }
};