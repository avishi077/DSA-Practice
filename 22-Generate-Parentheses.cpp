class Solution {
public:
    void parentheses(int &n, string cur, int open, int close, vector<string> &ans){
        if(cur.length()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            cur.push_back('(');
            parentheses(n, cur, open+1, close, ans);
            cur.pop_back();
        }
        if(close<open){
            cur.push_back(')');
            parentheses(n, cur, open, close+1, ans);
            cur.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parentheses(n, "", 0, 0, ans);
        return ans;
    }
};