#include <iostream>

using namespace std;

const int MAX_ROW = 10;
const int MAX_COL = 10;

void swapRows(int *firstRow, int *secondRow, int col);


int main(){
  int row, col, sortCol, top, i, j;
  cout << "Please input the rows and columns: ";
  cin >> row >> col;
  int matrix[row][col];
  cout << "Please input the matrix: ";
  for(i = 0; i < row; i++)
    for (j = 0; j<col; j++)
      cin >> matrix[i][j];
  cout << "Please input the sort number: ";
  cin >> sortCol;
  for (i = 0; i < row -1; i++){
    top = i;
    for(j = top+1; j< row; j++){
      if(matrix[top][sortCol] > matrix[j][sortCol])
        top = j;
    }
    swapRows(matrix[i], matrix[j], col);
  }
  cout << "The sorted matrix is:\n";
  for(i = 0; i < row; i++){
    for (j = 0; j < col; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

void swapRows(int *firstRow, int *secondRow, int col){
  int tempArray[col], i;
  for(i = 0; i < col; i++)
    tempArray[i] = firstRow[i];
  for(i = 0; i < col; i++)
    firstRow[i] = secondRow[i];
  for(i = 0; i < col; i++)
    secondRow[i] = tempArray[i];
}
