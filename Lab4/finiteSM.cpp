#include <iostream>

//making the code a little prettier
#define stateChecker finiteStateMachine[currentState][(currentInput == 'a') ? 0 : 1]

using namespace std;

int main(){
  /*
  State Table
    State | input | Output
          | a   b |
    --------------------
      S0  | S0 S1 | 0
    --------------------
      S1  | S3 S2 | 1
    --------------------
      S2  | S3 S2 | 0
    --------------------
      S3  | S5 S4 | 0
    --------------------
      S4  | S5 S5 | 1
    --------------------
      S5  | S5 S5 | 0
  */
  int currentState = 0, finiteStateMachine[6][3] = {
    {0, 1, 0},
    {3, 2, 1},
    {3, 2, 0},
    {5, 4, 0},
    {5, 5, 1},
    {5, 5, 0}
  };
  char currentInput;
  do{ //do while loop to read in the input and print out recognition state
    cout << finiteStateMachine[currentState][2];
    //using cin.get to read in the newline character
    cin.get(currentInput);
    //assigning the currentState to be the appropriate state determining on the input
    currentState = stateChecker;
    //checking to see if the inputs are valid
  } while(currentInput != '\n' || currentInput == 'a' || currentInput == 'b');
}
