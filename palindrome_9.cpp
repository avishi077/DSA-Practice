class Solution {
public:
    bool isPalindrome(int x) {
        int new1=0;
        int lastdigit;
        while(x>0){
            lastdigit=x%10;
            new1=(new1*10) + lastdigit;
            x=x/10;
        }
        if (new1==x){
            return true;
        }
        else {
            return false;
        }
        
    }
};