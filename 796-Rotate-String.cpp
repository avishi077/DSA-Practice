class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s.append(s);
        if(s.find(goal) != string::npos) return true;
        else return false;
    }
};