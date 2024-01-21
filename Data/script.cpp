#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>

using namespace std;

void populateGunOwners(unordered_map<string, array<double, 2>> &mainMap) {
    ifstream file;
    file.open("convertcsv.csv");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string element;
            string countryName, gunOwners;
            int i = 0;

            while (getline(ss, element, ',')) {
                if (i == 0) {
                  countryName = element;
                } else if (i == 1) {
                  gunOwners = element;
                }

                i++;
            }
            mainMap.emplace(countryName, array<double, 2>{stod(gunOwners), -1});
        }
      file.close();
    } else {
        return;
    }
}

void populateVictims(unordered_map<string, array<double, 2>> &mainMap) {
    ifstream file;
    file.open("something.csv");

    if (file.is_open()) {
      string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string element;
            string countryName, homicides;
            int i = 0;

            while (getline(ss, element, ',')) {
                if (i == 1) {
                  countryName = element;
                } else if (i == 3) {
                    homicides = element;
                }

                i++;
            }
            if (mainMap.find(countryName) != mainMap.end()){
              mainMap[countryName][1] = stod(homicides);
            } else {
              cout << "Does not exist " << countryName << ' ' << homicides << endl;
            }
        }
      
      file.close();
    } else {
        cout << "ERROR" << endl;
        return;
    }
}

void populateText(unordered_map<string, array<double, 2>> &mainMap){
  ofstream file;

  file.open("text.txt");

  if (file.is_open()){
    for (auto item : mainMap){
      file << item.first << ',' << item.second[0] << ',' << item.second[1] << endl;
    }
  } else {
    cout << "ERROR" << endl;

    return;
  }
}

int main() {
    unordered_map<string, array<double, 2>> mainMap;

    populateGunOwners(mainMap);
    populateVictims(mainMap);
    populateText(mainMap);

    // Now mainMap is populated with data from both functions
    return 0;
}
