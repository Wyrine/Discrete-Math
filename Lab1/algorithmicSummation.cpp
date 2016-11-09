#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
  int n, solution;
  cout << "Welcome to the Algorithmic Summation program. Please input the number\n";
  cout << "to compute: ";
  cin >> n;
  if(n < 1)
    cout << "Sorry but that's not a valid input. Must be 1 or greater.\n";
  else{
    ofstream output("algorithmicSol.txt", ios_base::app);
    double startTime = clock();
    solution = n*(n+1)/2;
    double endTime = clock();
    output << "n is " << n << " and the solution is " << solution << " with the";
    output << " time it took to find that solution being " << (endTime - startTime)/CLOCKS_PER_SEC << endl;
    output.close();
  }
}
