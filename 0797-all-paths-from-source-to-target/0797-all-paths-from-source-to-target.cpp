class Solution {
public:
    int src,dest;
    vector<int>v;
    vector<vector<int>>ans;
    void rec(int cur,vector<vector<int>>& graph){
        if(cur == dest){
            ans.push_back(v);
            return;
        }
        for(int i = 0;i < graph[cur].size();i++){
            if(graph[cur][i]){
                v.push_back(graph[cur][i]);
                rec(graph[cur][i],graph);
                v.pop_back();
            }
            else return;
            
            
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        src = 0;
        dest = graph.size()-1;
        v.push_back(0);
        rec(0,graph);
        

        return ans;
    }
};