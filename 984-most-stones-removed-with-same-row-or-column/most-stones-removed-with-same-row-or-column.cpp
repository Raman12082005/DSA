class Solution {
public:
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.assign(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUpar(int node){
        if(parent[node] == node) return node;

        // path compression
        return parent[node] = findUpar(parent[node]);
    }
    void UnionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) swap(ulp_u, ulp_v);
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
};
    int removeStones(vector<vector<int>>& stones) {
        // base cases
        int n = stones.size();



        int maxrow = 0;
        int maxcol = 0;
        for(int i=0; i<n; i++){
            maxrow = max(maxrow, stones[i][0]);
            maxcol = max(maxcol, stones[i][1]);
        }

        DisjointSet ds(maxrow + maxcol + 2);
        unordered_map<int, int> stonesnode;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            
            ds.UnionBySize(noderow, nodecol);

            stonesnode[noderow] = 1;
            stonesnode[nodecol] = 1;
        }

        int compo = 0;
        for(auto it : stonesnode){
            if(ds.findUpar(it.first) == it.first){
                compo++;
            }
        }
        return n - compo;
    }  
};