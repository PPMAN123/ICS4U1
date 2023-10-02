/**
 * @file Grades.cpp
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief
 * @date 2023-09-29
 */

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

// Prototypes
double homework();
double midterm();
void finalMark(double homeworkMark, double midtermMark);

int main() {
  // Printing out menu
  cout << "This program accepts your homework and exam\nscores as input, and "
          "computes your grade in the course or\nindicates what grade you need "
          "to earn on the final exam.\n"
       << endl;

  cout << setprecision(2) << fixed;

  cout << "Homework:" << endl;
  double homeworkMark =
      homework(); // Storing homework mark to put into final mark calculation
  cout << "\tYour weighted homework mark is " << homeworkMark << endl;

  cout << "Midterm exam:" << endl;
  double midtermMark =
      midterm(); // Storing midterm mark to calculate final mark
  cout << setprecision(1) << fixed;
  cout << "\tYour weighted midterm mark is " << midtermMark << endl;

  cout << "Final exam:" << endl;
  finalMark(homeworkMark, midtermMark);
}

// Function that handles logic for calculating homework marks
double homework() {
  int numOfAssignments;
  double weight, homeworkScore, homeworkMax = 0;

  // Collecting user info
  cout << "\tWhat is its weight (0-100)? ";
  cin >> weight;

  cout << "\tHow many homework assignments were there? ";
  cin >> numOfAssignments;

  // Loops and accumulates the scores and max scores
  for (int i = 0; i < numOfAssignments; i++) {
    float temp1, temp2; // Temporary variables to get user input with
    cout << "\tHomework " << i + 1 << " score and max score: ";
    cin >> temp1 >> temp2;

    // Accumutale to the according variables
    homeworkScore += temp1;
    homeworkMax += temp2;
  }

  return ((homeworkScore / homeworkMax) * weight); // Returns the weighted mark
}

// Function that handles calculations for midterm marks
double midterm() {
  int curveChoice;
  double weight, examScore, curve = 0;

  // Collecting user inputs
  cout << "\tWhat is its weight (0-100)? ";
  cin >> weight;

  cout << "\tExam score: ";
  cin >> examScore;

  cout << "\tWas there a curve? (1 for yes, 2 for no) ";
  cin >> curveChoice;

  if (curveChoice == 1) {
    // If there's a curve
    cout << "\tHow much was the curve? ";
    cin >> curve;

    return min(examScore + curve, 100.0) * weight /
           100.0; // Final mark is exam score and curve or 100, depending on
                  // which one is smaller
  }

  return examScore * weight /
         100.0; // If there's no curve return score * weight
}

// Function that handles the logic for calculating mark of final exams
void finalMark(double homeworkMark, double midtermMark) {
  int choice;
  double weight, examScore, curve, percentageGoal, finalMark;

  // Collect user input
  cout << "\tHave you taken the final exam yet? (1 for yes, 2 for no) ";
  cin >> choice;

  cout << "\tWhat is its weight (0-100)? ";
  cin >> weight;

  if (choice == 1) {
    // If user has taken exam

    // Collect input
    cout << "\tExam score: ";
    cin >> examScore;
    cout << "\tWas there a curve? (1 for yes, 2 for no) ";
    cin >> choice;

    if (choice == 1) {
      // If exam gets curved
      cout << "\tHow much was the curve? ";
      cin >> curve;

      cout << "\tWeighted exam score: "
           << (min(examScore + curve, 100.0) * weight / 100.0)
           << endl; // Curved mark calculation
    } else {
      // If exam is not being curved
      cout << examScore * weight / 100.0 << endl;
    }

    // Print out course grade
    cout << "\n\n\tYour course grade is "
         << (min(examScore + curve, 100.0) * weight / 100.0) + homeworkMark +
                midtermMark
         << '.' << endl;

  } else {
    // If user has not taken exam
    cout << "\tWhat percentage would you like to earn in the course? ";
    cin >> percentageGoal;

    finalMark = (percentageGoal - homeworkMark - midtermMark) / weight *
                100; // Calculate mark to get on exam

    cout << setprecision(2) << fixed;
    cout << "\tYou need a score of " << finalMark << " on the final exam."
         << endl;
    if (finalMark > 100) {
      // If mark needed to achieve average is too high, print out sorry messages
      cout << "\n\n\tSorry, it is impossible to achieve this percentage."
           << endl;
      cout << "\tThe highest percentage you can get is "
           << homeworkMark + midtermMark + weight << '.' << endl;
    }
  }
}