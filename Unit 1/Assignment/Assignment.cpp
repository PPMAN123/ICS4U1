/**
 * @author Ethan Zhou
 * @for: Mr.Saleem
 * @class ICS4U1
 * @brief A program that prints shapes with customizable dimensions
 * @date 2023-09-19
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using namespace std;

int getNumericalInput(int min, int max, string prompt) {
  // Function that gets numeric inputs, reduces code repetition
  // Returns an integer of a valid input
  int input;

  do {
    // Do loop to get input form user
    cout << '\n' << prompt;
    cin >> input;
    if (input < min || input > max) {
      // When user input is invalid, display error message that tells them what
      // to input
      cout << "\nERROR: Please input a number between " << min << " and " << max
           << endl;
    }
  } while (input < min || input > max);

  return input;
}

void drawHorizontalLine(int length) {
  // Function that draws a horizontal line
  for (int i = 0; i < length; i++) {
    // Loops through the length of the line, and prints a star
    cout << '*';
  }
  cout << endl;
}

void drawVerticalLine(int height) {
  // Function that draws a vertical line
  for (int i = 0; i < height; i++) {
    // Loops through the height of the line, prints a star and starts new line
    cout << '*' << endl;
  }
}

void drawRectangle(int width, int height) {
  // Function that draws a rectangle
  for (int i = 0; i < height; i++) {
    // Loops through the height of rectangle
    for (int j = 0; j < width; j++) {
      // Loops through the width of the rectangle, then prints out a star with a
      // new line
      cout << '*';
    }
    cout << endl;
  }
}

void drawLeftSlantTriangle(int height) {
  // Function that draws a right triangle that slants to the left
  for (int i = 0; i < height; i++) {
    // Loops through the height of the triangle
    for (int j = 0; j < i + 1; j++) {
      // Loops until number of stars per row, to print stars
      cout << '*';
    }
    cout << endl;
  }
}

void drawRightSlantTriangle(int height) {
  // Function that draws a right triangle that slants to the right
  for (int i = 0; i < height; i++) {
    // Loops through the height of the triangle
    for (int j = 0; j < height - i; j++) {
      // Loops until height - i to print spaces to format triangle
      cout << ' ';
    }
    for (int j = 0; j < i + 1; j++) {
      // Loops until i + 1 to print the number of stars per line
      cout << '*';
    }
    cout << endl;
  }
}

void drawIsoscelesTriangle(int height) {
  // Function that draws an isoscles triangle
  for (int i = 1; i <= height; i++) {
    // Loops through the height of the triangle
    for (int j = 0; j < height - i; j++) {
      // Loops height - i to print number of spaces to format triangle
      cout << ' ';
    }
    for (int j = 0; j < i + (i - 1); j++) {
      // Loop to print proper number of stars per line
      cout << '*';
    }
    cout << endl;
  }
}

void drawBox(int height) {
  // Function that draws a box given the height
  drawHorizontalLine(height * 2); // Prints top horizontal line of box

  for (int i = 0; i < height - 2; i++) {
    // Loops until height - 2 for the middle columns
    for (int j = 1; j <= height; j++) {
      // Loops until the height of the box
      if (j == 1) {
        // Prints the first star of each row
        cout << "* "; // Uses space for formatting
      } else if (j == height) {
        // Prints the last star of each row
        cout << " *"; // Uses space for formatting
      } else {
        // Prints the spaces in the middle of column
        cout << "  ";
      }
    }
    cout << endl;
  }

  drawHorizontalLine(height * 2); // Draws horizontal line to close off box
}

void drawGlass(int width) {
  // Function that draws a glass given the width
  for (int i = 1; i <= width; i += 2) {
    // Loops through the width at 2x speed to get height
    for (int j = 0; j < round(i) / 2; j++) {
      // Loops until i / 2 rounded to print number of stars on the left
      cout << '*';
    }
    for (int j = 0; j < width - (i + 1); j++) {
      // Loops until width - (i + 1) to get number of spaces in between two
      // sides
      cout << ' ';
    }
    for (int j = 0; j < round(i) / 2; j++) {
      // Loops until i / 2 rounded to print number of stars on the right
      if (width % 2 != 0 && j + 1 >= round(i) / 2 && i + 1 > width) {
        // If statement that checks if width is odd and at the last star, to
        // prevent it from printing, since it causes issues
        break;
      }
      cout << '*';
    }
    cout << endl;
  }
}

int menu() {
  // Function that prints out the menu and returns the user choice

  // Printing out the menu
  cout << "Choose shape (specified by numbers)" << endl;
  cout << "\ti) Horizontal line" << endl;
  cout << "\tii) Vertical line" << endl;
  cout << "\tiii) Rectangle" << endl;
  cout << "\tiv) Left slant right angle triangle" << endl;
  cout << "\tv) Right slant right angle triangle" << endl;
  cout << "\tvi) Isosceles triangle" << endl;
  cout << "\tvii) Box" << endl;
  cout << "\tviii) Glass" << endl;

  return getNumericalInput(1, 8, "Enter your choice (1-8): ");
}

int main() {
  char drawAnother; // Char to keep track of user input for drawing more shapes
  unordered_map<string, int> shapeCount = {
      {"Horizontal Line", 0},
      {"Vertical Line", 0},
      {"Rectangle", 0},
      {"Left Slant Triangle", 0},
      {"Right Slant Triangle", 0},
      {"Isosceles Triangle", 0},
      {"Box", 0},
      {"Glass", 0}}; // Unordered map that keeps track of shape names and amount
                     // of times they were made
  do {
    // Do loop that keeps asking users to draw more shapes when they choose to
    system("clear"); // Clears the screen every
    switch (menu()) {
      // Switch that sorts out user inputs
    case 1:
      // Cases draw shapes and increments according counters
      drawHorizontalLine(
          getNumericalInput(2, 20, "Enter the length of the line: "));
      shapeCount["Horizontal Line"]++;
      break;
    case 2:
      drawVerticalLine(
          getNumericalInput(2, 20, "Enter the height of the line: "));
      shapeCount["Vertical Line"]++;
      break;
    case 3:
      drawRectangle(
          getNumericalInput(2, 20, "Enter the width of the rectangle: "),
          getNumericalInput(2, 20, "Enter the height of the rectangle: "));
      shapeCount["Rectangle"]++;
      break;
    case 4:
      drawLeftSlantTriangle(
          getNumericalInput(2, 20, "Enter the height of the triangle: "));
      shapeCount["Left Slant Triangle"]++;
      break;
    case 5:
      drawRightSlantTriangle(
          getNumericalInput(2, 20, "Enter the height of the triangle: "));
      shapeCount["Right Slant Triangle"]++;
      break;
    case 6:
      drawIsoscelesTriangle(
          getNumericalInput(3, 20, "Enter the height of the triangle: "));
      shapeCount["Isosceles Triangle"]++;
      break;
    case 7:
      drawBox(getNumericalInput(2, 20, "Enter the width of the box: "));
      shapeCount["Box"]++;
      break;
    case 8:
      drawGlass(getNumericalInput(5, 20, "Enter width of the glass: "));
      shapeCount["Glass"]++;
      break;
    }

    do {
      // Do while loop that error traps and gets value for user's input to draw
      // another shape
      cout << "Would you like to draw another one (y/n): ";
      cin >> drawAnother;
      if (tolower(drawAnother) != 'y' && tolower(drawAnother) != 'n') {
        cout << "\nError: Please enter y or n" << endl;
      }
    } while (tolower(drawAnother) != 'y' && tolower(drawAnother) != 'n');

  } while (tolower(drawAnother) == 'y');

  cout << "\nHere is a summary of the shapes that were drawn.\n" << endl;

  for (auto shape : shapeCount) {
    // Loops through the unordered map and prints out the shape name and number
    // of times it's been created
    cout << setw(30) << left << shape.first;
    cout << right << shape.second;
    cout << endl;
  }

  cout << "\nThank you for using Shape Generator. Goodbye!!" << endl;

  return 0;
}