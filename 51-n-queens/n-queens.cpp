class Solution {
public:
    bool issafe(vector<string>chess,int row,int col,int n ){
        for(int i = 0 ;i < n ;i++){
            if(chess[row][i] == 'Q')return false;
        }

        for(int i = 0 ;i < n ;i++){
            if(chess[i][col] == 'Q')return false;
        }

        for(int i = row, j = col ;i >= 0 && j >= 0 ;i--,j--){
            if(chess[i][j] == 'Q')return false;
        }

        for(int i = row, j = col; i >= 0 && j < n ;i--,j++){
            if(chess[i][j] == 'Q')return false;
        }

        return true;

    }
    void Solve(vector<string> &chess,int row ,int n,vector<vector<string>>& ans){
        if (row == n){
            ans.push_back(chess);
            return;
        }

        for(int i =0;i<n;i++){
            if(issafe(chess,row,i,n)){
                chess[row][i] = 'Q';
                Solve(chess , row + 1 , n , ans);
                chess[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>chess(n,string(n,'.'));
        Solve(chess,0,n,ans);
        return ans;
    }
};