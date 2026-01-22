class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> FreqOfChar;
        for(int i=0; i<s.size(); i++) FreqOfChar[s[i]]++;

        vector<pair<char, int>> freq(FreqOfChar.begin(), FreqOfChar.end());
        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });

        s.resize(0);
        for(auto &p : freq){
            s +=string(p.second, p.first);
        }
        return s;
    }
};