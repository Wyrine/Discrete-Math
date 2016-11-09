//Kirolos Shahat
//computing the summation of the n variable given by the user using
//recursion

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//recursive summation function prototype
int s(int n);

int main(){
  //variables to be used
  int n, solution;
  //greeting the user
  cout << "Welcome to the Algorithmic Summation program. Please input the number\n";
  cout << "to compute: ";
  //reading in the value of n from the user
  cin >> n;
  //if n is not valid, loops until a valid one is provided
  while(n < 1){
    cout << "Sorry, but that's not a valid input. Must be 1 or greater.\n";
    cin >> n;
  }
  //open the output file to write to and have set it to append and not overwrite
  ofstream output("algorithmicSol.txt", ios_base::app);
  //set the start time to the current value of the clock
  double startTime = clock();
  //call s(n) to do the calculation which returns the solution
  solution = s(n);
  //set the stop time to the current value of the clock
  double endTime = clock();
  //print out to the output file the n used, the value that was calculated and the time it took to solve
  output << "n is " << n << " and the solution is " << solution << " with the";
  output << " time it took to find that solution being " << (endTime - startTime)/CLOCKS_PER_SEC << endl;
  //close the file and finish
}

//s is a recursive summation function which returns an integer being that instance
//of the function's solution to the sum
//n is an integer value in which the summation of it is asked for
int s(int n){
  //if n is equal to 1, return 1 is the base case
  if (n == 1) return 1;
  //otherwise return the value that s(n-1) returns + the current value of n
  else return (s(n-1)+n);
}
