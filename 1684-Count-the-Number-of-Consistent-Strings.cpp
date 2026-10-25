
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool present[26] = {};

        for (char c : allowed) {
            present[c - 'a'] = true;
        }

        int count = 0;

        for (const string& word : words) {
            bool valid = true;

            for (char c : word) {
                if (!present[c - 'a']) {
                    valid = false;
                    break;
                }
            }

            if (valid) count++;
        }

        return count;
    }
};
