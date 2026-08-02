class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        string ans="";
        int maxi=1;
        for(int i=0;i<s.length();i++){
            int left=i;
            int right=i;
            while(left>-1 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            int len = right - left - 1;
            if(len > maxi) {
                maxi = len;
                start = left + 1;
            }
            left=i;
            right=i+1;

            while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
            }

            len = right-left-1;

            if(len > maxi){
                maxi=len;
                start=left+1;
            }
        }
        return s.substr(start, maxi);
    }
};