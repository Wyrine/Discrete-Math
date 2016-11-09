#include <iostream>

using namespace std;

const int MAX_ROW = 10;
const int MAX_COL = 10;

void swapRows(int *firstRow, int *secondRow, int col);


int main(){
  int row, col, sortCol, top, i, j, temp, k;
  cout << "Please input the rows and columns: ";
  cin >> row >> col;
  int matrix[row][col];
  cout << "Please input the matrix: ";
  for(i = 0; i < row; i++)
    for (j = 0; j<col; j++)
      cin >> matrix[i][j];
  cout << "Please input the sort number: ";
  cin >> sortCol;
  sortCol--;
  for (i = 0; i < row -1; i++){
    top = i;
    for(j = top+1; j< row; j++){
      if(matrix[top][sortCol] > matrix[j][sortCol])
        top = j;
    }
    for( k = 0; k < col; k++){
      temp = matrix[i][k];
      matrix[i][k] = matrix[top][k];
      matrix[top][k] = temp;
    }
  }
  cout << "The sorted matrix is:\n";
  for(i = 0; i < row; i++){
    for (j = 0; j < col; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

void swapRows(int *firstRow, int *secondRow, int col){
  int tempVal;
  for(int i = 0; i < col; i++){
    tempVal = firstRow[i];
    firstRow[i] = secondRow[i];
    secondRow[i] = tempVal;
  }
}
