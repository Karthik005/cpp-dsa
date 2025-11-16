#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool find_path(const vector<vector<bool>> &grid, vector<pair<int, int>> &current_path,
               int row, int col, vector<vector<bool>> &visited)
{

    int num_rows = grid.size()-1, num_cols = grid[0].size()-1;
    if (row == num_rows && col == num_cols) {
        current_path.push_back(pair<int,int>{row, col});
        return true;
    }

    // for (auto i : current_path)
    // {
    //     cout << "(" << i.first << "," << i.second << ")";
    // }
    visited[row][col] = true;
    current_path.push_back(pair<int,int>{row, col});
    
    if (col < num_cols && !visited[row][col + 1] && grid[row][col + 1])
    {
        if (find_path(grid, current_path, row, col+1, visited)) return true;
    }

    if (row < num_rows && !visited[row + 1][col] && grid[row + 1][col])
    {
        if (find_path(grid, current_path, row+1, col, visited)) return true;
    }
    
    //if neither works out
    current_path.pop_back();
    return false;

}

int main(){
    vector<vector<bool>> grid {
        {true,true,true,false},
        {true,true,false,false},
        {true,false,true,true},
        {true,false,true,true},
    };

    vector<vector<bool>> visited(4, vector<bool>(4,false));
    vector<pair<int,int>> path;
    bool value = find_path(grid, path, 0,0, visited);
    cout << "Value is:"<<value<<endl;
    for (auto i : path) {
        cout << "(" << i.first << "," << i.second << ")" <<endl;
    }
}