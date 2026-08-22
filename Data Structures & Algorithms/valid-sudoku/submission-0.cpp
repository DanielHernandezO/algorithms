class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            unordered_set<char> row;
            for(int j=0;j<9;++j){
                if(row.count(board[i][j])) return false;
                if(board[i][j]!='.') row.insert(board[i][j]);
            }
        }

        for(int i=0;i<9;++i){
            unordered_set<char> column;
            for(int j=0;j<9;++j){
                if(column.count(board[j][i])) return false;
                if(board[j][i]!='.') column.insert(board[j][i]);
            }
        }

        map<pair<int, int>, unordered_set<char>> m;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                pair<int, int> key = {floor(i/3.0), floor(j/3.0)};
                if(m[key].count(board[i][j])) return false;
                if(board[i][j]!='.') m[key].insert(board[i][j]);
            }
        }

        return true;
    }
};
