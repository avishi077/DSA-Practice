class Solution {
public:
    string reverseWords(string s) {
        string words[1000];
        int count=0;
        for(int i=0;i<s.size();i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(word!= ""){
                words[count]=word;
                count++;
            }
        }
        string result="";
        for(int i=count-1;i>=0;i--){
            result+=words[i];
            if(i!=0){
                result+=' ';
            }
        }
        return result;
    }
};