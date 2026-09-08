class Solution {
public:
    bool start=false;
    bool neg=false;
    bool maxi=false;
    
    void atoi(string s, int i, int &num){
        if(i==s.size()) return;
        if (s[i] < '0' || s[i] > '9'){
            if(s[i]==' '){
                if(start){
                    return;
                }
                atoi(s, i + 1, num);
                return;
            }
            if(s[i]=='-' || s[i]=='+'){
                if(start){
                    return;
                }
                else if(!start && (s[i]=='+')){
                    start=true;
                }
                else if(!start && s[i]=='-'){
                    start=true;
                    neg=true;
                }
                else if(s[i]=='-'){
                    neg=true;
                }
                atoi(s, i + 1, num);
                return;
            }
            return;
        }
        else{
            start=true;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > 7)){
                maxi=true;
                return;
            }
            else if (num < INT_MIN / 10 || (num == INT_MIN / 10 && (s[i] - '0') > 7)){
                maxi=true;
                return;
            }
            num=num*10+(s[i] - '0');
            atoi(s, i+1, num);
        }
    }
    int myAtoi(string s) {
        int num=0;
        atoi(s,0,num);
        if(neg){
            if(maxi){
                return INT_MIN;
            }
            return -num;
        }
        else{
            if(maxi){
                return INT_MAX;
            }
            return num;
        }
    }
};