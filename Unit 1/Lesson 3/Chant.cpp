#include <iostream>
#include <string>

using namespace std;

bool soundVowel(char character){
  const int vowelSoundsNum = 12;
  char vowelSounds[vowelSoundsNum] = {'a','e','f','h','i','l','m','n','o','r','s','x'};
  for (int i = 0; i < vowelSoundsNum; i++){
    if (character == vowelSounds[i]){
      return true;
    }
  }
}

int main(){
  string word;
  cout << "Cheer: ";
  cin >> word;

  for (int i = 0; i < word.length(); i++){
    cout << "Give me " << (soundVowel(word[i]) ? "an" : "a") << ' ' << word[i] << endl;
  }

}