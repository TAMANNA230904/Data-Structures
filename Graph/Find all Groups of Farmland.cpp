You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland.
These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland
in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). 
Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1)
and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland,
return an empty array. You may return the answer in any order.



class Solution {
public:
 void dfs(int r,int c,vector<vector<int>>& land,vector<int>& ans,vector<vector<bool>>& visited){
    int row=land.size();
    int col=land[0].size();
    visited[r][c]=1;
    if(r==row-1 && c==col-1){
         ans.push_back(r);
         ans.push_back(c);
    }else if(r+1<=row-1 && c+1<=col-1 && land[r+1][c]==0 && land[r][c+1]==0){
         ans.push_back(r);
         ans.push_back(c);
    }else if(r==row-1 && land[r][c+1]==0){
         ans.push_back(r);
         ans.push_back(c);
    }else if(c==col-1 && land[r+1][c]==0){
         ans.push_back(r);
         ans.push_back(c);
    }
    

    


    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int rr=r+dr[i];
            int cc=c+dc[i];
            if(rr>=0 && cc>=0 && rr<=row-1 && cc<=col-1 && land[rr][cc]==1 && visited[rr][cc]==0)
            dfs(rr,cc,land,ans,visited);
        }
    }
 }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row=land.size();
        int col=land[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> visited(row,vector<bool>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j]==1 && visited[i][j]==0){
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    dfs(i,j,land,ans,visited);
                    res.push_back(ans);
                }
            }
        }
return res;
    }
};
