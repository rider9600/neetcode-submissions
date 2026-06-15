class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
     int row=grid.size();
     int col=grid[0].size();   
   
     int p=0;

     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                

             if(i==0)p++;
             if(j==0)p++;
             if(i==row-1)p++;
             if(j==col-1)p++;

             if(i+1<row && grid[i+1][j]==0)p++;
             if(i-1>=0 && grid[i-1][j]==0) p++;
             if(j+1<col && grid[i][j+1]==0)p++;
             if(j-1>=0 && grid[i][j-1]==0) p++;
             cout<<i<<" "<<j<<" "<<p<<endl;  
            }
        }
     }
    return p;
    }
};