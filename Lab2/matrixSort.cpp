//Kirolos Shahat
//creating a matrix as a specific size given by the user
//and reading in that matrix from the user, asking the user which
//column they want sorted from the matrix and sorting that column.
//if a swap is done in the column then the whole row is swapped with
//it

#include <iostream>

using namespace std;

int main(){
  //all the needed variables
  int row, col, sortCol, top, i, j, temp;
  //asking the user for the row and column to be used
  cout << "Please input the rows and columns: ";
  cin >> row >> col;
  //creating a matrix of that size
  int matrix[row][col];
  cout << "Please input the matrix: ";
  //reading in the elements from the user into the matrix
  for(i = 0; i < row; i++)
    for (j = 0; j<col; j++)
      cin >> matrix[i][j];
  //asking the user which column they would like to sort
  cout << "Please input the sort number: ";
  cin >> sortCol;
  //decrementing the sorted column by 1 to account for the math to programming
  //translation
  sortCol--;
  //doing a selection sort
  for (i = 0; i < row -1; i++){
    top = i;
    for(j = top+1; j< row; j++){
      //if a swap needs to occur
      if(matrix[top][sortCol] > matrix[j][sortCol])
        //top becomes the value of j
        top = j;
    }
    //swapping the rows that need to swap
    for(j = 0; j < col; j++){
      temp = matrix[i][j];
      matrix[i][j] = matrix[top][j];
      matrix[top][j] = temp;
    }
  }
  //printing out the sorted matrix
  cout << "The sorted matrix is:\n";
  for(i = 0; i < row; i++){
    for (j = 0; j < col; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}
