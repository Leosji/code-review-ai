#include "password_generator.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Fix me: Добавлена функция для вывода меню
void printMenu() {
  cout << "Password Generator\n";
  cout << "Choose complexity level:\n";
  cout << "1 - Simple (8 chars, letters only)\n";
  cout << "2 - Medium (12 chars, letters and digits)\n";
  cout << "3 - Strong (16 chars, letters, digits and symbols)\n";
}

int main() {
  try {
    PasswordGenerator generator;
    int complexityLevel;
    
    printMenu();
    cout << "Your choice (1-3): ";
    cin >> complexityLevel;

    string password = generator.generatePassword(complexityLevel);
    cout << "Your password: " << password << endl;
  }
  catch (const std::exception& e) {
    cout << "Error: " << e.what() << endl;
    return 1;
  }

  return 0;
}
