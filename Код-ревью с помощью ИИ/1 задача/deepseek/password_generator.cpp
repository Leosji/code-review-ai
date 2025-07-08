#include "password_generator.h"
#include <random>
#include <ctime>
#include <stdexcept>

using std::string;

//Fix me: Добавлена проверка уровня сложности
bool PasswordGenerator::isValidComplexityLevel(int level) const {
  return level >= 1 && level <= 3;
}

//Fix me: Логика выбора набора символов вынесена в отдельный метод
string PasswordGenerator::getCharsetForLevel(int level) const {
  const string lowercase = "abcdefghijklmnopqrstuvwxyz";
  const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const string digits = "0123456789";
  const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

  switch (level) {
    case 1:
      return lowercase + uppercase;
    case 2:
      return lowercase + uppercase + digits;
    case 3:
      return lowercase + uppercase + digits + symbols;
    default:
      return "";
  }
}

//Fix me: Логика выбора длины вынесена в отдельный метод
int PasswordGenerator::getPasswordLengthForLevel(int level) const {
  switch (level) {
    case 1:
      return 8;
    case 2:
      return 12;
    case 3:
      return 16;
    default:
      return 0;
  }
}

//Fix me: Добавлена обработка исключений и разделение логики
string PasswordGenerator::generatePassword(int complexityLevel) {
  if (!isValidComplexityLevel(complexityLevel)) {
    throw std::invalid_argument("Invalid complexity level");
  }

  string charset = getCharsetForLevel(complexityLevel);
  int length = getPasswordLengthForLevel(complexityLevel);

  // Инициализация генератора случайных чисел
  std::mt19937 rng(std::time(nullptr));
  std::uniform_int_distribution<size_t> dist(0, charset.size() - 1);

  string password;
  for (int i = 0; i < length; ++i) {
    password += charset[dist(rng)];
  }

  return password;
}
