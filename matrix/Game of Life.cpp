// https://leetcode.com/problems/game-of-life/
// see traversal in count function
// we just change value in this question

class Solution {
public:
    int count(vector<vector<int>>& a,int i,int j){
        int ans=0;
        int r=a.size();
        int c=a[0].size();
        for(int x=max(i-1,0);x<min(i+2,r);x++){
            for(int y=max(j-1,0);y<min(j+2,c);y++){
                if(x==i&&y==j){
                    continue;
                }
                else if(a[x][y]==1||a[x][y]==2){
                    ans++;
                }
            }
        }
        return ans;
    }
    void update(vector<vector<int>>& a){
        int r=a.size();
        int c=a[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==-1){
                    a[i][j]=1;
                }
                else if(a[i][j]==2){
                    a[i][j]=0;
                }
            }
        }
    }
    void gameOfLife(vector<vector<int>>& a) {
        int r=a.size();
        int c=a[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==0){
                    int res=count(a,i,j);
                    if(res==3){
                        a[i][j]=-1;
                    }
                }
                else if(a[i][j]==1){
                    int res=count(a,i,j);
                    if(res<2||res>3){
                        a[i][j]=2;
                    }
                }
            }
        }
        update(a);
    }
};
