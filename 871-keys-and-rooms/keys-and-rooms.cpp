class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int currnode = q.front();
            q.pop();

            for(auto neighbour : rooms[currnode]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        auto it = find(visited.begin(), visited.end(), false);
        if(it == visited.end()){
            return true;
        }
        return false;
    }
};