#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

bool flipCoin ();

int main () {
  int tailCount = 0;
  int headCount = 0;
  char userDecision;
  srand(time(NULL));  // srand must be initialized in main to create new random numbers quickly

  while (userDecision != 'n') {
    cout << "Flip a coin? (Y for yes, N for no. Press F to leave the choice to fate!): ";
    std::cin >> userDecision;
    bool trueorfalse = flipCoin();

    if (userDecision == 'y' || userDecision == 'Y') {
      if (trueorfalse == true) {
        headCount=headCount+1;
        cout << "Heads: " << headCount << " |  Tails: " << tailCount << endl;
      }
      else if (trueorfalse == false) {
        tailCount=tailCount+1;
        cout << "Heads: " << headCount << " |  Tails: " << tailCount << endl;
      }
    }

    else if (userDecision == 'n' || userDecision == 'N') {
      break;
    }

    // Work on this so it counts heads and tails separately on each call rather than just 100 times.
    else if (userDecision == 'f' || userDecision == 'F') {
      for (int i=0; i < 100; i++) {
        bool trueorfalse2 = flipCoin();
        if (trueorfalse2 == true) {
          headCount=headCount+1;
        }
        else if (trueorfalse2 == false) {
          tailCount=tailCount+1;
        }
      }
      cout << "Heads: " << headCount << " |  Tails: " << tailCount << endl;
    }

    else {
      std::cout << "Please input the correct command." << '\n';
    }
  }
  cout << "\nFINAL COUNT: "<< endl;
  cout << "Heads: " << headCount << "   |  Tails: " << tailCount;

  if (headCount > tailCount) {
    std::cout << "        ...Head WINS!" << '\n';
  }
  else if (tailCount > headCount) {
      std::cout << "        ...Tails WINS!" << '\n';
  }
  else if (tailCount == headCount) {
    std::cout << "        ...it's a TIE!" << '\n';
  }
  return 0;
}

bool flipCoin () {
  int somenumber = 0;
  somenumber = (rand() %100) + 1;
  //number check
  cout << somenumber << endl;

  if (somenumber%2!=0) { // odd numbers, or heads
    return true;
  }
  else return false;  // even numbers, or tails
}
