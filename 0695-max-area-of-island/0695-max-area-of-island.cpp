class Solution {
public:
    int n,m,c = 0,ans = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& v,int x,int y){
        v[x][y] = 1;
        c++;
        for(int i = 0;i < 4;i++){
            int xx = dx[i]+x;
            int yy = dy[i]+y;
            if(xx >= 0 and xx < n and yy >= 0 and yy < m){
                if(!v[xx][yy] and grid[xx][yy]) dfs(grid,v,xx,yy);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n = grid.size();
        m = grid[0].size();
        vector<vector<int>> v( n,vector<int> (m, 0)); 
        
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] and !v[i][j]){
                    dfs(grid,v,i,j);
                    ans = max(ans,c);
                    c = 0;
                }
                   
            
                
            }
        }
        return ans;
    }
};