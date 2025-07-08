#include "PasswordGenerator.h"
#include <cstdlib>
#include <ctime>

PasswordGenerator::PasswordGenerator() {
  srand(time(0)); // Инициализация генератора случайных чисел
}

std::string PasswordGenerator::generatePassword(int length, const std::string& characters) {
  std::string password;
  for (int i = 0; i < length; ++i) {
    password += characters[rand() % characters.size()];
  }
  return password;
}
