#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void rotate_matrix_rec (int** matrix, int rows, int offset){
    int end_ind = rows-offset-1;
    int start_ind = offset;
    int interim_val = 0;

    if (start_ind >= end_ind){
        return;
    }

    for(int i=start_ind; i<end_ind; ++i){
        interim_val = matrix[start_ind][i];
        matrix[start_ind][i] = matrix[end_ind-i][start_ind];
        matrix[end_ind-i][start_ind] = matrix[end_ind][end_ind-i];
        matrix[end_ind][end_ind-i] = matrix[i][end_ind];
        matrix[i][end_ind] = interim_val;
    }

    rotate_matrix_rec(matrix, rows, offset+1);
}

void rotate_matrix(int** matrix, int rows){
    rotate_matrix_rec(matrix, rows, 0);
}

void print_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** create_matrix(int rows, char const** argv){
    int** matrix = new int*[rows];
    int k = 2;
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[rows];
        for (int j = 0; j < rows; ++j, ++k)
        {
            matrix[i][j] = atoi(argv[k]);
        }
    }
    print_matrix(matrix, rows);
    return matrix;
}

void delete_matrix(int** matrix, int rows){
    for (int i=0; i<rows; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char const *argv[])
{
    int rows = atoi(argv[1]);
    int **matrix = create_matrix(rows, argv);
    rotate_matrix(matrix, rows);
    cout<<endl;
    print_matrix(matrix, rows);
    delete_matrix(matrix, rows);
    return 0;
}
