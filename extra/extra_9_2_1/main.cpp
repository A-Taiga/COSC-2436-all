//// problem from workshop

#include <iostream>
using namespace std;

int main() {

    const int ROW_SIZE = 10;
    const int COLUMN_SIZE = 10;

    int **arr = new int*[ROW_SIZE];

    for(int i = 0; i < ROW_SIZE; i++) {
        arr[i] = new int[COLUMN_SIZE];
    }
    for(int r = 0; r < ROW_SIZE; r++) {
        for(int c = 0; c < COLUMN_SIZE; c++) {
            arr[r][c] = rand() % 10;
        }
    }
    for(int r = 0; r < ROW_SIZE; r++) {
        for(int c = 0; c < COLUMN_SIZE; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < ROW_SIZE; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}