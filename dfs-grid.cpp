class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n) return false;
        if(vis[i][j]==1||grid[i][j]!=1) return false;
        return true;
    }
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(!isValid(i,j,grid,vis)) return 0;
        
        vis[i][j]=1;  // OR set grid[i][j]=0;
        int area=1;
        
        for(auto dir:dirs){
            area+=dfs(i+dir[0],j+dir[1],grid,vis);
        }
        
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,0)); // OR set grid[i][j]=0;
        int maxi=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    maxi=max(maxi,dfs(i,j,grid,vis));
            }
        }
        
        return maxi;
    }
};
