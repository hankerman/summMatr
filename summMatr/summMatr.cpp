#include <iostream>
#define ABS(X,Y) ((X > Y)? X : Y)

using namespace std;

void createMatr(int**& arr, int row, int cols) {

    arr = new int* [row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols];
    }

}

void fill(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void delMatr(int**& arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

void summ(int** matr, int** matr2, int** matr3, int row, int row2, int row3, int cols, int cols2, int cols3) {
    for (int i = 0; i < row3; i++) {
        for (int j = 0; j < cols3; j++) {
            if (i < row && i < row2) {
                if (j < cols && j < cols2) {
                    matr3[i][j] = matr[i][j] + matr2[i][j];
                }
                else if (j <= cols && j >= cols2) {
                    matr3[i][j] = matr[i][j];
                }
                else if (j <= cols2 && j >= cols) {
                    matr3[i][j] = matr2[i][j];
                }
            }
            else if (i < row && i >= row2) {
                if (j < cols && j < cols2) {
                    matr3[i][j] = matr[i][j];
                }
                else if (j < cols2 && j >= cols) {
                    matr3[i][j] = 0;
                }
                else {
                    matr3[i][j] = 1;
                }
            }
            else if (i < row2 && i >= row) {
                if (j < cols2 && j < cols) {
                    matr3[i][j] = matr2[i][j];
                }
                else if (j < cols && j >= cols2) {
                    matr3[i][j] = 0;
                }
                else {
                    matr3[i][j] = 1;
                }
            }

        }
    }
}

int main()
{
    
    /*Написать программу, которая поэлементно 
    суммирует два динамических двумерных массива, заполненных случайными числами и сохраняет результат 
    в третьем массиве. Размеры исходных массивов задаются 
    пользователем.*/

    int row, cols, row2, cols2, row3, cols3;

    int** matr = nullptr;
    int** matr2 = nullptr;
    int** summarMatr = nullptr;

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter cols: ";
    cin >> cols;
    cout << "Enter row2: ";
    cin >> row2;
    cout << "Enter cols2: ";
    cin >> cols2;
    row3 = ABS(row, row2);
    cols3 = ABS(cols, cols2);
    cout << "row3 - " << row3 << endl;
    cout << "cols3 - " << cols3 << endl;

    createMatr(matr, row, cols);
    createMatr(matr2, row2, cols2);
    createMatr(summarMatr, row3, cols3);

    fill(matr, row, cols);
    fill(matr2, row2, cols2);

    summ(matr, matr2, summarMatr, row, row2, row3, cols, cols2, cols3);

    print(matr, row, cols);
    print(matr2, row2, cols2);
    print(summarMatr, row3, cols3);

    delMatr(matr, row);
    delMatr(matr2, row2);
    delMatr(summarMatr, row3);
}