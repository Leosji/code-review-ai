#include "PasswordGenerator.h"
#include <iostream>
#include <string>
#include <cctype> // для std::isdigit
//ChatGPT
void printMenu()
{
  using std::cout;
  using std::endl;

  cout << "Password Generator" << endl;
  cout << "Choose complexity level:" << endl;
  cout << "1 - Simple (10 chars, letters only)" << endl;
  cout << "2 - Medium (14 chars, letters and digits)" << endl;
  cout << "3 - Strong (18 chars, letters, digits and symbols)" << endl;
}

int main()
{
  try
  {
    using std::cin;
    using std::cout;
    using std::endl;

    PasswordGenerator generator;
    std::string input;

    printMenu();
    cout << "Your choice (1-3): ";

    if (!(cin >> input))
    {
      throw std::invalid_argument("Failed to read input");
    }

    // Fix me: Проверяем, что введена ровно одна цифра от '1' до '3'
    if (input.size() != 1 || !std::isdigit(input[0]) || input[0] < '1' || input[0] > '3')
    {
      throw std::invalid_argument("Invalid input: please enter a single digit from 1 to 3");
    }

    int complexityLevel = input[0] - '0';

    const std::string password = generator.generatePassword(complexityLevel);
    cout << "Your password: " << password << endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
