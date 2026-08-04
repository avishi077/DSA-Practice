class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int> even, odd;
        for(int i=0;i<s.size();i++){
            if(s[i]%2==0){
                even.push_back(s[i]);
                s[i]='0';
            }
            else{
                odd.push_back(s[i]);
                s[i]='1';
            }
        }
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int e=0, o=0;
        for(int i=0;i<s.size();i++){
            if (s[i]=='0'){
                s[i]=even[e];
                e++;
            }
            else{
                s[i]=odd[o];
                o++;
            }
        }
        num = stoi(s);
        return num;
    }
};