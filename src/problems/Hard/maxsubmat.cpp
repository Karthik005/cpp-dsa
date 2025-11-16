#include "../../Utils/headers.hpp"

using namespace std;


struct mat_ind
{
    int row, col;
    void print(){cout <<"("<<row<<","<<col<<")"<<endl;}
};

pair<mat_ind, mat_ind>
get_max_submat(const vector<vector<int>> &base_mat)
{
    int rows = base_mat.size();
    if (rows == 0)
        return pair<mat_ind, mat_ind>{{-1, -1}, {-1, -1}};

    mat_ind max_start{0, 0};
    mat_ind max_end{0, 0};
    int max_sum = base_mat[0][0];
    vector<vector<pair<int, mat_ind>>> sum_matr(
            base_mat.size(), vector<pair<int,mat_ind>>(rows, pair<int,mat_ind>{0,max_start}));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            int prev_sum = 0;
            mat_ind top_ind{i, j};
            mat_ind left_ind{i, j};
            bool choose_top = false;
            if (i < 1)
            {
                if (j >= 1)
                {
                    (prev_sum = sum_matr[i][j - 1].first);
                    left_ind = sum_matr[i][j - 1].second;
                }
                else
                {
                    prev_sum = -1;
                }
            }
            else if (j < 1)
            {
                if ((prev_sum = sum_matr[i - 1][j].first) > 0)
                {
                    choose_top = true;
                    top_ind = sum_matr[i - 1][j].second;
                }
            }
            else
            {
                top_ind = sum_matr[i - 1][j].second;
                left_ind = sum_matr[i][j - 1].second;
                if (top_ind.row == left_ind.row)
                {
                    prev_sum = (sum_matr[i - 1][j].first + sum_matr[i][j - 1].first -
                                sum_matr[i - 1][j - 1].first);
                    choose_top = true;
                }
                else
                {
                    prev_sum = max<int>(sum_matr[i - 1][j].first,
                                        sum_matr[i][j - 1].first);
                    choose_top = (prev_sum == sum_matr[i - 1][j].first);
                }
            }

            if (prev_sum < 0)
            {
                sum_matr[i][j].first = base_mat[i][j];
                sum_matr[i][j].second = mat_ind{i, j};
            }
            else
            {
                sum_matr[i][j].first = base_mat[i][j] + prev_sum;
                sum_matr[i][j].second =
                    (choose_top ? top_ind : left_ind);
            }
            if (sum_matr[i][j].first > max_sum)
            {
                max_start = sum_matr[i][j].second;
                max_end = mat_ind{i, j};
                max_sum = sum_matr[i][j].first;
            }
            cout << sum_matr[i][j].first << " " << prev_sum<<endl;
            sum_matr[i][j].second.print();
        }

    }
    return pair<mat_ind, mat_ind>{max_start, max_end};
}


int main() {
    vector<vector<int>> matr{
        {-2,5,-3},
        {7,6,-1},
        {2,3,5},
    };
    pair<mat_ind, mat_ind> indices = get_max_submat(matr);
    indices.first.print();
    indices.second.print();
}
