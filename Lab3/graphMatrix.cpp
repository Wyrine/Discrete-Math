//Kirolos Shahat
//program that takes the number of nodes there are in a graph and builds an
//adjacency relation and then manipulates that data into information for the user

#include <iostream>

using namespace std;

//prototypes for the functions to be used
int menu();
int getDegree(int *node, int adjacency);

int main(){
  //variables needed
  int n, node1AndChoice, node2AndChoice, menuChoice, i, j, numOddNodes = 0;
  char junk;
  cout << "Welcome to the adjacency relation program! Please input the number of\n";
  cout << "nodes there are in your graph: ";
  cin >> n;
  //declaring the adjacency relation matrix
  int adjacencyMatrix[n][n];
  //declaring an array for the degree's of the matrix. This enhances run-time but
  //hurts memory allocation for bigger sizes
  int degree[n];
  //initializing all of the elements in the matrix to zero
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      adjacencyMatrix[i][j] = 0;
  cout << "Please input a binary relation for the nodes in your graph:\n";
  //reading in the first curly brace
  cin >> junk;
  do{
    //reading in the set of relations and an extra character as junk
    cin >> junk >> node1AndChoice >> junk >> node2AndChoice >> junk >> junk;
    //if the two relations are the same, there is a loop so
    //the adjacency at that location is 2
    if(node1AndChoice == node2AndChoice) adjacencyMatrix[node1AndChoice -1][node2AndChoice-1] = 2;
    //otherwise just set the given node's adjacency to 1
    else adjacencyMatrix[node1AndChoice-1][node2AndChoice-1] = 1;
  //the break condition is if the last junk character read is a '}'
  }while(junk != '}');
  //updating the degree array to the proper value per node
  for(i = 0; i < n; i++){
    degree[i] = getDegree(adjacencyMatrix[i], n);
    //counting the number of odd nodes there are in a graph for Euler path
    //recognition
    if(degree[i] % 2 != 0) numOddNodes++;
  }
  //the loop that has the menu and the calculations
  do{
    //asking the user which menu option they would like to see
    menuChoice = menu();
    //the switch statement for the menu choice and what they would like to see
    switch(menuChoice){
      case 1: //print the matrix
        for (i = 0; i < n; i++){
          for (j = 0; j < n; j++)
            cout << adjacencyMatrix[i][j] << " ";
          cout << endl;
        }
        break;
      case 2: //determine if there are any isolated nodes
        for(i = 0; i < n; i++)
          if(degree[i] == 0) cout << "Node " << i+1 << " is an isolated node.\n";
        break;
      case 3: //determine the degree of a node
        cout << "Which node are you interested in? ";
        cin >> node1AndChoice;
        cout << "Node " << node1AndChoice << "'s degree is: "
            << degree[node1AndChoice-1] << endl;
        break;
      case 4: //determine if an euler path exists
        if(numOddNodes == 0 || numOddNodes == 2)
          cout << "An Euler path exists for this relation.\n";
        else
          cout << "No Euler path exists for this relation.\n";
        break;
      case 5: //determine if one node is adjacent to another
        cout << "Which nodes are you interested in? ";
        cin >> node1AndChoice >> node2AndChoice;
        if(adjacencyMatrix[node1AndChoice-1][node2AndChoice-1] > 0 &&
            adjacencyMatrix[node2AndChoice-1][node1AndChoice-1] > 0)
          cout << "The nodes are adjacent to each other.\n";
        else
          cout << "The nodes are not adjacent to each other.\n";
        break;
    }
  }while(menuChoice != 6);
  cout << "Thank you for using this program! Goodbye!\n";
}

//prints the menu to the user, take the user's choice and makes sure that
//it's valid, if not, loops until a valid input is chosen and returns it
int menu(){
  int choice;
  cout << "Select one of the following options:\n"
      << "1. Print the adjacency matrix\n"
      << "2. Determine if there are any isolated nodes\n"
      << "3. Determine the degree of a node\n"
      << "4. Determine if a Euler path exists\n"
      << "5. Determine if one node is adjacent to another\n"
      << "6. Quit\n";
  cin >> choice;
  //the error checking
  while(choice<1 || choice > 6){
    cout << "Error. Please select an option between 1 and 6:";
    cin >> choice;
  }
  return choice;
}

//add's up the values of the node and gets the sum which is the degree
//and returns it back to the user
int getDegree(int *node, int adjacency){
  int sum = 0;
  for (int i = 0; i < adjacency; i++)
    sum+= node[i];
  return sum;
}
