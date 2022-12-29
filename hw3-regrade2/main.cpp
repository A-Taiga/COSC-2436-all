#include "ArgumentManager.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void print_matrix(const vector<vector<char>> &matrix) {
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
void shift_up(const vector<vector<char>> &matrix, const size_t &row, const size_t &col, vector<vector<char>> &result_matrix) 
{
  Stack s;
  int counter = 0;
  // char temp;

  for(int j = 0; j < col; j++) {
    for(int i = 0; i < row; i++) {
      if(matrix[i][j] != 'O' && matrix[i][j] != 'X') {
        if(!s.isEmpty() && s.peek() == 'B') {
          s.pop();
          s.push('X');
        } else {
          s.push(matrix[i][j]);
        }
      } else if(matrix[i][j] == 'X') {
        while(s.getSize() < counter) {
          s.push('O');
        }
        s.push('X');
      }
      counter ++;
    }
    while(s.getSize() < counter)
      s.push('O');

    for(int i = row -1; i >= 0; i--)
      result_matrix[i][j] = s.pop();

    counter = 0;
  }
}
void shift_down(const vector<vector<char>> &matrix, const size_t &row, const size_t &col, vector<vector<char>> &result_matrix) 
{
  Stack s;
  int counter = 0;
  // char temp;


  for(int j = col-1; j >= 0; j--) {
    for(int i = row-1; i >= 0; i--) {
      if(matrix[i][j] != 'O' && matrix[i][j] != 'X') {
        if(!s.isEmpty() && s.peek() == 'B') {
          s.pop();
          s.push('X');
        } else {
          s.push(matrix[i][j]);
        }
      } else if(matrix[i][j] == 'X') {
        while(s.getSize() < counter) {
          s.push('O');
        }
        s.push('X');
      }
      counter ++;
    }
    while(s.getSize() < counter)
      s.push('O');

    for(int i = 0; i < row; i++)
      result_matrix[i][j] = s.pop();

    counter = 0;
  }
}
void shift_right(const vector<vector<char>> &matrix, const size_t &row, const size_t &col, vector<vector<char>> &result_matrix)
{
    Stack s;
    int counter = 0;
    // char temp;

    for(int i = 0; i < row; i++) {
      for(int j = col-1; j >= 0; j--) {
        if(matrix[i][j] != 'O' && matrix[i][j] != 'X') {
          if(!s.isEmpty() && s.peek() == 'B') {
            s.pop();
            s.push('X');
          } else {
            s.push(matrix[i][j]);
          }
        } else if(matrix[i][j] == 'X') {
          while(s.getSize() < counter) {
            s.push('O');
          }
          s.push('X');
        }
        counter++;
      }
    while(s.getSize() < counter)
      s.push('O');
    for (int j = 0; j < col; j++)
      result_matrix[i][j] = s.pop();
    counter = 0;
  }
}
void shift_left(const vector<vector<char>> &matrix, const size_t &row, const size_t &col, vector<vector<char>> &result_matrix)
{
  Stack s;
  int counter = 0;

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] != 'O' && matrix[i][j] != 'X') {
        if(!s.isEmpty() && s.peek() == 'B') {
          s.pop();
          s.push('X');
        } else {
          s.push(matrix[i][j]);
        }
      } else if(matrix[i][j] == 'X') {
        while(s.getSize() < counter) {
          s.push('O');
        }
        s.push('X');
      }
      counter++;
    }
    while(s.getSize() < counter)
      s.push('O');
    for (int j = col - 1; j >= 0; j--)
      result_matrix[i][j] = s.pop();
    counter = 0;
  }
}
bool has_changed(const vector<vector<char>> &m1, const vector<vector<char>> &m2,int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(m1[i][j] != m2[i][j]) {
        return true;
      }
    }
  }
  return false;
}
bool is_solved(const vector<vector<char>> &matrix, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == 'B')
        return false;
    }
  }
  return true;
}
void reset(vector<vector<char>> &matrix) {
  for(int i = 0; i < matrix.size(); i++)
    for(int j = 0; j < matrix[i].size(); j++)
      matrix[i][j] = 'O';
}
int main(int argc, char *argv[]) {

  typedef void (*shifting) (const vector<vector<char>> &matrix, const size_t &row, const size_t &col, vector<vector<char>> &result_matrix);
  const int S_SIZE = 4;
  shifting moves[S_SIZE] = {&shift_up, &shift_right, &shift_down, &shift_left}; // an array of function pointers

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));


  // ifstream input("input2.txt");
  // ofstream output("output.txt");

  size_t row;
  size_t col;
  input >> row; // input row
  input >> col; // input column

  vector<vector<char>> matrix; // input matrix

  // reading the matrix from the input
  for (int i = 0; i < row; i++) {
    vector<char> temp;
    for (int j = 0; j < col; j++) {
      char c;
      input >> c;
      temp.push_back(c);
    }
    matrix.push_back(temp);
  }

  Queue q;

  vector<vector<char>> temp_matrix(row,vector<char>(col,'O'));

  for(int i = 0; i < S_SIZE; i++) {
    moves[i](matrix,row,col,temp_matrix);
    if(has_changed(matrix,temp_matrix,row,col)) {
        Pair queue_pair;
        queue_pair.matrix = temp_matrix;
        queue_pair.moves = to_string(i+1);
        q.enqueue(queue_pair);
        
        reset(temp_matrix);
      }
  }




  while(!q.isEmpty()) {
    reset(temp_matrix);
    Pair dq = q.dequeue();
    if(is_solved(dq.matrix,row,col)) {
      output << dq.moves << endl;
      break;
    }
    for(int i = 0 ;i < S_SIZE; i++) {
      moves[i](dq.matrix,row,col,temp_matrix);
      if(has_changed(dq.matrix,temp_matrix,row,col)) {
        q.enqueue(Pair(temp_matrix, dq.moves + to_string(i+1)));
      }
    }
  }
  return 0;
}
