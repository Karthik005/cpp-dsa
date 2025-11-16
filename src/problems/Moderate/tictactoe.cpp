#include <vector>
#include <iostream>
#include "../../Utils/print_funcs.cpp"

using namespace std;

bool has_won(const vector<vector<char>>& board) {
    if (board.size() !=3) return false;
    vector<vector<int>> horz, vert, diag;
    int nbox = board.size();
    horz = vert = diag = vector<vector<int>>(nbox, vector<int>(nbox, 1));
    for (int row = 0; row < nbox; row++) {
        for (int col = 0; col < nbox; col ++) {
            char current = board[row][col];
            cout << current<<endl;
            //check left
            if (col-1 >= 0 && (board[row][col-1] ==  current)) {
                horz[row][col] = horz[row][col - 1] + 1;
                // print_matrix<int>(horz);
            }
            if (row - 1 >= 0 && (board[row-1][col] == current)) {
                vert[row][col] = vert[row - 1][col] + 1;
            }

            if (row == nbox -1 && col == nbox -1  && board[row-1][col-1] == current &&
                board[row-2][col-2] == current){
                return true;
            }
            if (col == 0 && row == nbox - 1 && board[row - 1][col + 1] == current &&
                board[row - 2][col + 2] == current) {
                
                return true;
            }

            if (row == nbox-1 && vert[row][col] == nbox) return true;
            if (col == nbox-1 && horz[row][col] == nbox) return true;
        }
    }
    print_matrix<int>(vert);
    print_matrix<int>(horz);
    print_matrix<int>(diag);
    return false;
}

int main() {
    vector<vector<char>> myvec {
        {'x','o','o'},
        {'x','x','o'},
        {'o','x','x'},
    };
    cout << has_won(myvec) << endl;
}