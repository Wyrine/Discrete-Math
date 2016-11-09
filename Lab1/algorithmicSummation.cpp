//Kirolos Shahat
//computing the summation of the n variable given by the user using
//an equation and no iteration/recursion

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

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
  //do the calculation N*(N+1)/2 which gives the sum of the integers
  solution = n*(n+1)/2;
  //set the stop time to the current value of the clock
  double endTime = clock();
  //print out to the output file the n used, the value that was calculated and the time it took to solve
  output << "n is " << n << " and the solution is " << solution << " with the";
  output << " time it took to find that solution being " << (endTime - startTime)/CLOCKS_PER_SEC << endl;
  //close the file and finish
  output.close();
}
