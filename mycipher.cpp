#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>
#include <cctype>
using namespace std;

int main() {
  int n;
  int d = (26 - n);
  cout << "Enter amount to shift: ";
  cin >> n;
  cin.ignore();
  string message;
  cout << "Enter message to encode: ";
  getline(cin, message);
  
 
 int counter2 = 0;
 for (int j = 0; j < message.length(); j++){
    if (message.at(j) >= 97 && message.at(j) <= 122){
        message.at(j) = message.at(j) - 32;
    }
    else if ((message.at(j) >= 0 && message.at(j) <= 64) || (message.at(j) >= 91 && message.at(j) <= 127)){
        message.at(j) = 32;
        counter2++;
    }
  }
 
 int counter1 = 0;
  for (int z = 0; z < message.length() + counter2; z++){
      if (message[z] != ' '){
          message[counter1++] = message[z];
      }
      else{
          message[counter1] = '\b';
      }
  }
 
  
  for (int i = 0; i < message.length(); i++){
    message.at(i) = message.at(i) + n;
    if (message.at(i) > 90){
        message.at(i) = (message.at(i)) - 26;
    }
  }
  
  
  
  list<char> characters = {};
  for (int k = 0; k < message.length(); k++){
      if (message.at(k) >= 65 && message.at(k) <= 90){
          characters.push_back(message.at(k));
      }
  }
  

  int counter3 = 0;
  int counter4 = 0;
  for (char letter:  characters){
      if (counter3 % 5 == 0){
          cout << " ";
      }
      if (counter4 % 50 == 0){
          cout << '\n';
      }
      cout << letter;
      counter3++;
      counter4++;
  }
}
