class Solution {
public:
    bool isPalindrome(string s) {
        string n="";
        for (char ch : s){
            if (isalnum(ch)){
                n+=tolower(ch);
            }
        }
        for(int i = 0; i < n.size()/2; i++) {
            if(n[i] != n[n.size()-i-1]) {
                return false;
            }
        }
        return true;
    }
};