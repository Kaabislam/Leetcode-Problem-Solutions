class Solution {
public:
    int n,m;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& v,int x,int y){
        v[x][y] = 1;
        for(int i = 0;i < 4;i++){
            int xx = dx[i]+x;
            int yy = dy[i]+y;
            if(xx >= 0 and xx < n and yy >= 0 and yy < m){
                if(!v[xx][yy] and !grid[xx][yy]) dfs(grid,v,xx,yy);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> v( n,vector<int> (m, 0)); 
        
        for(int i = 0;i < m;i++){
            if(!grid[0][i] and !v[0][i]){
                dfs(grid,v,0,i);
            }
        }
        for(int i = 0;i < m;i++){
            if(!grid[n-1][i] and !v[n-1][i]){
                dfs(grid,v,n-1,i);
            }
        }        
        for(int i = 0;i < n;i++){
            if(!grid[i][0] and !v[i][0]){
                dfs(grid,v,i,0);
            }
        }
        for(int i = 0;i < n;i++){
            if(!grid[i][m-1] and !v[i][m-1]){
                dfs(grid,v,i,m-1);
            }
        }
        int c = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!grid[i][j] and !v[i][j]){
                    c++;
                    dfs(grid,v,i,j);
                }
            }
        }
        
        return c;
    }
};