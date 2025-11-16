#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

typedef vector<vector<int>> Matrix;
static const int SENTINEL = -1;


void set_zero(Matrix& matr, int row, int col) {
    int num_rows = matr.size();
    int num_cols = matr[0].size();

    if (col != SENTINEL) {
        for(int i=0; i<num_rows; ++i) {
            matr[i][col] = 0;
        }
    }

    if (row != SENTINEL) {
        for (int i = 0; i < num_cols; ++i)
        {
            matr[row][i] = 0;
        }
    }
}

void change_row_col(Matrix& matr) {
    unordered_set<int> col_set;
    unordered_set<int> row_set;
    int num_rows, num_cols;
    if ((num_rows=matr.size()) == 0) return;
    if ((num_cols=matr[0].size()) == 0) return;

    for(int i=0; i<num_rows; ++i) {
        for (int j=0; j<num_cols; ++j) {
            if (matr[i][j] == 0) {
                col_set.insert(j);
                row_set.insert(i);
                break;
            }
        }
    }

    for (const int& row : row_set) {
        set_zero(matr, row, SENTINEL);
    }

    for (const int &col : col_set)
    {
        set_zero(matr, SENTINEL, col);
    }
}


int main() {
    vector<vector<int>> apple(10);
    for (int i = 0 ; i<10; ++i){
        apple[i] = vector<int>(10);
        for (int j = 0 ; j<10; ++j) {
            apple[i][j] = (((j+1) % 9) + i);
            cout << apple[i][j] << " ";
        }
        cout << endl;
    }

    cout <<endl <<endl;

    change_row_col(apple);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout<<apple[i][j]<<" ";
        }
        cout << endl;
    }
}