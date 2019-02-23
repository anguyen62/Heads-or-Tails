#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

// function declaration
bool flipCoin ();
void count (int headCount, int tailCount);
void tallyResults (int headCount, int tailCount);

int main () {
  int tailCount = 0;
  int headCount = 0;
  char userDecision;
  srand(time(NULL));

  // While the user does not say "no", continue loop.
  while (userDecision != 'n' || userDecision != 'N') {
    cout << "Flip a coin? (Y for yes, N for no. Press F if you want to flip a certain number of times!): ";
    cin >> userDecision;
    bool trueorfalse = flipCoin();

    if (userDecision == 'y' || userDecision == 'Y') {
      if (trueorfalse == true) {
        headCount=headCount+1;
        count (headCount, tailCount);
      }
      else if (trueorfalse == false) {
        tailCount=tailCount+1;
        count (headCount, tailCount);
      }
    }

    else if (userDecision == 'n' || userDecision == 'N') {
      break;
    }

    else if (userDecision == 'f' || userDecision == 'F') {
      cout << "How many times would you like to flip?: ";
      int numberofFlips;
      cin >> numberofFlips;

      if (cin.fail()) {
        cout << "Enter a valid integer for number of flips." << endl;
      }

      else {
      for (int i=0; i < numberofFlips; i++) {
        bool trueorfalse2 = flipCoin();
        if (trueorfalse2 == true) {
          headCount=headCount+1;
        }
        else if (trueorfalse2 == false) {
          tailCount=tailCount+1;
        }
      }
      count (headCount, tailCount);
    }
  }
    else {
      cout << "Please input the correct command." << '\n';
    }
  }

  // If loop ends, count number of flips and which side wins.
  cout << "\nFINAL COUNT: "<< endl;
  count (headCount, tailCount);
  tallyResults (headCount, tailCount);

  return 0;
}

bool flipCoin () {
  int somenumber = 0;
  somenumber = (rand() %100) + 1;
  //number check. Comment out if you wanna prove correctness.
  //cout << somenumber << " / ";

  if (somenumber%2 != 0) { // odd numbers, or heads
    return true;
  }
  else return false;  // even numbers, or tails
}

void count (int headCount, int tailCount) {
  cout << "  Heads: " << headCount << " |  Tails: " << tailCount << endl;
}

void tallyResults (int headCount, int tailCount) {
  if (headCount > tailCount) {
    cout << "        ...Head WINS!" << '\n';
  }
  else if (tailCount > headCount) {
      cout << "        ...Tails WINS!" << '\n';
  }
  else if (tailCount == headCount) {
    cout << "        ...it's a TIE!" << '\n';
  }
}
