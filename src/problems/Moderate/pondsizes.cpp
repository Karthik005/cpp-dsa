#include "headers.hpp"
using namespace std;

int call_rec(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col,
             int n_rows, int n_cols);

int get_connected_water(const vector<vector<int>>& grid, vector<vector<bool>> &visited, int row, int col,
                        int n_rows, int n_cols) {
    int size = 1;
    visited[row][col] = true;
    for (int r = row-1; r <=row+1; r++) {
        for (int c = col - 1; c <= col  + 1; c++) {
            if (r == row && c == col) continue;
            size += call_rec(grid, visited, r, c,
                             n_rows, n_cols);
        }
    }

    return size;
}

int call_rec(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col,
             int n_rows, int n_cols) {
    if (row >= 0 && row < n_rows && col >= 0 && col < n_rows) {
        if (grid[row][col] == 0 && !visited[row][col]){
            return get_connected_water(grid, visited, row, col,
                                       n_rows, n_cols);
        }
    }

    return 0;
}


vector<int> get_pond_sizes(const vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0]. size() == 0) throw invalid_argument("Not a grid");
    int n_cols = grid[0].size(), n_rows = grid.size();
    vector<int> result;
    vector<vector<bool>> visited(n_rows, vector<bool>(n_cols, false));

    for (int row = 0; row<n_rows; row++){
        for (int col = 0; col < n_cols; col++) {
            if (visited[row][col]) continue;
            if (grid[row][col] == 0) {
                result.push_back(
                    get_connected_water(grid, visited, row, col,
                                        n_rows, n_cols)
                                );
            } else {
                visited[row][col] = true;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> grid {
            {0,2,1,0},
            {0,1,0,1},
            {1,1,0,1},
            {0,1,0,1}
    };
    print_vec(get_pond_sizes(grid));
}