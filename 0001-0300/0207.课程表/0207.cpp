// 依次移除入度为0的节点，更新图，如果最后还剩下有节点，则说明有环。
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        unordered_map<int, vector<int> > adj;  // 记录每个节点的相邻边(指向的边)
        for (auto eage : prerequisites){
            in_degree[eage[0]]++;
            if (adj.count(eage[1]))
                adj[eage[1]].push_back(eage[0]);
            else
                adj[eage[1]] = {eage[0]};
        }
        queue<int> q; 
        for (int i = 0; i < numCourses; i++){
            if (in_degree[i] == 0) 
                q.push(i);
        }
        while (!q.empty()){
            int u = q.front(); 
            q.pop(); 
            // Iterate through all its neighbouring nodes of dequeued node u and decrease their in-degree by 1.
            for (auto adj_node : adj[u])
                // If in-degree becomes zero, add it to queue
                if (--in_degree[adj_node] == 0) 
                    q.push(adj_node);
            adj.erase(u);
        }
        if (adj.empty())
            return true;
        else
            return false;
    }
};
