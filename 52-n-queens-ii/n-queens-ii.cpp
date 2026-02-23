class Solution {
public:
    bool issafe(vector<string>chess, int row, int col,int n){
        for(int i = 0;i < n;i++){
            if(chess[row][i] == 'Q')return false;
        }
        for(int i = 0;i < n;i++){
            if(chess[i][col] == 'Q')return false;
        }
        for(int i = row,j = col;i >= 0 && j >= 0 ;i-- , j--){
            if(chess[i][j] == 'Q')return false;
        }
        for(int i = row,j = col;i >= 0 && j < n;i--,j++){
            if(chess[i][j] =='Q')return false;
        }
        return true;
    }

    void solve(vector<string>& chess, int n , int row, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back({chess});
            return;
        }

        for(int i =0 ;i<n;i++){
            if(issafe(chess,row,i,n)){
            chess[row][i]='Q';
            solve(chess,n,row+1,ans);
            chess[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>chess(n,string(n,'.'));
        vector<vector<string>>ans;
        solve(chess,n,0,ans);
        return ans.size();
    }
};