class Solution {
public:
    vector<vector<char>> board;
    Solution(){
        board.resize(3, vector<char>(3, '.'));
    }
    bool diagonal(int x, int y ){ // check if the cell lies in diagonal 
        if(x == y)
            return true;
        for(int i = 2, j = 0; i>=0 && j<= 2 ; i--, j++){
            if(x == i && y == j)
                return true;
        }
        return false;
    }
    bool diagcheck(int x ,int y ){
        char ch = board[x][y];
        bool ok = true;
        for(int i = 2, j = 0; i>=0 && j<= 2 ; i--, j++){
            if(board[i][j] != ch){
                ok = false;
                break;
            }
        }
        if(ok) return ok;
        for(int i=0;i<3;i++){
            if(board[i][i] != ch){
                return false;
            }
        }
        return true;
    }
    bool rowcheck(int x, int y){
        char ch = board[x][y];
        for(int i=0;i<3;i++)
            if(board[x][i] != ch)
                return false;
        return true;
    }
    bool colcheck(int x, int y){
        char ch = board[x][y];
        for(int i=0;i<3;i++){
            if(board[i][y] != ch)
                return false;
        }
        return true;
    }
    string tictactoe(vector<vector<int>>& moves) {
        bool first= true; // first player
        for(auto &move: moves){
            int x, y;
            x = move[0];
            y = move[1];
            if(first){
                board[x][y] = 'X';
                if(diagonal(x,y)){
                    if(diagcheck(x,y))
                        return "A";
                }
                if(rowcheck(x,y) || colcheck(x,y))
                    return "A";
                first = false;
            }
            else{
                board[x][y] = 'O';
                if(diagonal(x,y)){
                    if(diagcheck(x,y))
                        return "B";
                }
                if(rowcheck(x,y) || colcheck(x,y))
                    return "B";
                first = true;
            }
        }
        if(moves.size() < 9) // the cells aren't completely filled 
            return "Pending";
        return "Draw";
    }
};
