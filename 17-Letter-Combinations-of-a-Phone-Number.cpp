class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void solve(string digits, int index, string &current, vector<string> &result){
        if(index==digits.size()){
            result.push_back(current);
            return;
        }
        char digit = digits[index];
        for(char ch:mp[digit]){
            current.push_back(ch);
            solve(digits, index+1, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current;
        solve(digits, 0, current, result);
        return result;
    }
};