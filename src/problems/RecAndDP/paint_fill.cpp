#include <iostream>
#include <vector>
#include "../../Utils/print_funcs.cpp"

using namespace std;

void fill_color_rec(vector<vector<int>>& grid, int fill_color, int orig_color, int row, int col, vector<vector<bool>>& visited) {
    if (visited[row][col]) return;
    
    visited[row][col] = true;
    if (grid[row][col] == orig_color) {
        grid[row][col] = fill_color;
    } else {
        return;
    }

    if (col+1 < grid[0].size()) {
        fill_color_rec(grid, fill_color, orig_color, row, col+1, visited);
    }
    if (col-1 >= 0) {
        fill_color_rec(grid, fill_color, orig_color, row, col-1, visited);
    }
    if (row+1 < grid.size()) {
        fill_color_rec(grid, fill_color, orig_color, row+1, col, visited);
    }
    if (row-1 >= 0) {
        fill_color_rec(grid, fill_color, orig_color, row-1, col, visited);
    }
    
}

int fill_color(vector<vector<int>>& grid, int fill_color, int row, int col ) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int orig_color = grid[row][col];
    fill_color_rec(grid, fill_color, orig_color, row, col, visited);
}

int main() {
    vector<vector<int>> grid = {
        {5,5,5,5,5},
        {5,4,5,5,5},
        {5,4,4,4,5},
        {5,4,4,5,5},
        {5,5,5,5,5}
    };
    fill_color(grid, 10, 2,2);
    for (auto i : grid) {
        print_vec(i);
    }
}
