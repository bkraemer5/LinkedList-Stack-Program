#include <iostream>
#include <fstream>
#include <string>
#include "LinkedStack.h"

using namespace std;

void readInput(string & i, LinkedStack<int> & stack);

int main() {
  LinkedStack<int> myStack;
  ifstream inData;
  inData.open("input.txt");
  string i;
  while(getline(inData, i)) {
    readInput(i, myStack);
  }
  inData.close();
  return 0;
}

// this function takes in string input, then 
void readInput(string & input, LinkedStack<int> & stack) {

  // left characters stored in symbols[0-2]
  // right characters stored in symbols[3-5]
  char *symbols = new char[6] {'(', '{', '[', ')', '}', ']'};

  for (int i = 0; i < input.length(); i++) {
    
    // searches through the left symbols, then pushes to stack
    for (int j = 0; j < 3; j++) {
      if(input[i] == symbols[j]) {
        stack.push(j);
      }
    }

    // searches through the right symbols, pops the corresponding left symbol from stack
    for (int j = 3; j < 6; j++) { 
      if (input[i] == symbols[j]) {
        // j-3 is corresponding left symbol
        if (j-3 == stack.peek()) {
          stack.pop();
        }
      }
    }
  }

  if (stack.isEmpty() == true) {
    cout << "Expression is valid" << endl;
  }
  else {
    cout << "Expression is invalid" << endl;
  }
  while (!stack.isEmpty()) {
    stack.pop();
  }
  delete [] symbols;
}
