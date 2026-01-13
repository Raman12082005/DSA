class Solution {
public:
    vector<string> restoreIpAddresses(string str){
        // base cases
        if(str.size() < 4 || str.size() > 12) return {};
        for(int i=0; i<str.size(); i++){
            if(!(str[i] >= '0' && str[i] <= '9')){
                return {};
            }
        }

        vector<string> ans;
        int n = str.size();
        for(int i=0; i<3 && i<n; i++){
            if(stoi(str.substr(0, i+1)) > 255) break;
            if(i>0 && str[0] == '0') break;

            for(int j=i+1; j<i+4 && j<n; j++){
                if(j > i+1 && str[i+1] == '0') break;
                if(stoi(str.substr(i+1, j-i)) > 255) break;

                for(int k=j+1; k<j+4 && k<n; k++){
                    if(k >= n-1) continue;

                    if(k > j+1 && str[j+1] == '0') break;
                    if(stoi(str.substr(j+1, k-j)) > 255) break;

                    string last = str.substr(k+1);
                    if(last.size() == 0 || last.size() > 3) continue;
                    if(last.size() > 1 && last[0] == '0') continue;
                    if(stoi(last) > 255) continue;

                    string s = str.substr(0, i+1) + '.' + str.substr(i+1, j-i) + '.' +
                               str.substr(j+1, k-j) + '.' + last;
                    
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};