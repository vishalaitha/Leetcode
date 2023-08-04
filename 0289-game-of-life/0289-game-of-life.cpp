class Solution {
public:
    vector<vector<int>>v;
    int n,m;
    int neighbours(int i,int j){
        if(i<0||i>=n||j<0||j>=m){
            return 0;
        }
        else if(v[i][j]==1) return 1;
        else return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        v=board;
        n=board.size();
        m=board[0].size();
        vector<vector<int>>ans=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // give 8 directions
                int neigh=0;
                if(v[i][j]==1){
                    neigh+=neighbours(i,j+1);
                    // left
                    neigh+=neighbours(i,j-1);
                    // top
                    neigh+=neighbours(i-1,j);
                    // bottom
                    neigh+=neighbours(i+1,j);
                    // ne
                    neigh+=neighbours(i-1,j+1);
                    // se
                    neigh+=neighbours(i+1,j+1);
                    // sw
                    neigh+=neighbours(i+1,j-1);
                    // nw
                    neigh+=neighbours(i-1,j-1);
                    if(neigh<2) ans[i][j]=0;
                    else if(neigh==2||neigh==3) ans[i][j]=1;
                    else ans[i][j]=0;
                }
                else{
                    // right
                    neigh+=neighbours(i,j+1);
                    // left
                    neigh+=neighbours(i,j-1);
                    // top
                    neigh+=neighbours(i-1,j);
                    // bottom
                    neigh+=neighbours(i+1,j);
                    // ne
                    neigh+=neighbours(i-1,j+1);
                    // se
                    neigh+=neighbours(i+1,j+1);
                    // sw
                    neigh+=neighbours(i+1,j-1);
                    // nw
                    neigh+=neighbours(i-1,j-1);
                    if(neigh==3) ans[i][j]=1;
                }
                
            }
        }
        board=ans;
    }
};