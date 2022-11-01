class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int a = image[sr][sc];
        queue<pair<int,int>>q;
        bool v[image.size()][image[0].size()];
        for(int i = 0;i < image.size();i++)
            for(int j = 0;j < image[0].size();j++)
                v[i][j] = false;
        q.push(make_pair(sr,sc));
        v[sr][sc] = true;
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int,int>x = q.front();
            q.pop();
            int xx = x.first,yy = x.second;
            for(int i = 0;i < 4;i++){
                int xx = x.first+dx[i],yy = x.second + dy[i];
                if(xx >= 0 and xx < image.size() and yy >= 0 and yy < image[0].size()){
                if(v[xx][yy] == false and image[xx][yy] == a){
                    v[xx][yy] = true;
                    image[xx][yy] = color;
                    q.push(make_pair(xx,yy));
                }
            }
            }
            
        }
        
        return image;
    }
};