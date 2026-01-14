class Solution {
public:
    class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n);

            for(int i=0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUpar(int node){
            if(parent[node] == node){
                return node;
            }
            // path compression
            return parent[node] = findUpar(parent[node]);
        }
        void UnionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if(ulp_u == ulp_v) return;
            else if(size[ulp_u] > size[ulp_v]){
                size[ulp_u] += size[ulp_v];
                parent[ulp_v] = ulp_u;
            }
            else{
                size[ulp_v] += size[ulp_u];
                parent[ulp_u] = ulp_v;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }
        
        vector<vector<string>> mergeMail(n);
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergeMail[i].size() == 0) continue;

            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};