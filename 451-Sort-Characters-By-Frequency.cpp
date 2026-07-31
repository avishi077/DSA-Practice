class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        string ans="";
        for(int i=0;i<v.size();i++){
            ans.append(v[i].second, v[i].first);
        }
        return ans;
    }
};