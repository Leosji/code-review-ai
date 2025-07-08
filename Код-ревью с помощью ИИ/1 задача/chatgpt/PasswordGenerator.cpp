#include "passwordGenerator.h"
#include <random>
#include <ctime>
#include <iostream>

// Возвращает набор символов по уровню сложности
std::string getCharacterSet(int difficultyLevel)
{
  std::string lower = "abcdefghijklmnopqrstuvwxyz";
  std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string digits = "0123456789";
  std::string symbols = "!@#$%^&*()-_=+[]{};:,.<>?";

  if (difficultyLevel == 1)
  {
    return lower;
  }

  if (difficultyLevel == 2)
  {
    return lower + upper + digits;
  }

  return lower + upper + digits + symbols;
}

// Возвращает длину пароля по уровню сложности
int getPasswordLength(int difficultyLevel)
{
  if (difficultyLevel == 1)
  {
    return 6;
  }

  if (difficultyLevel == 2)
  {
    return 10;
  }

  return 16;
}

// Генерирует случайный пароль
std::string generatePassword(int difficultyLevel)
{
  std::string charset = getCharacterSet(difficultyLevel);
  int length = getPasswordLength(difficultyLevel);
  std::string password;

  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> dist(0, static_cast<int>(charset.size()) - 1);

  for (int i = 0; i < length; ++i)
  {
    char randomChar = charset[dist(generator)];
    password += randomChar;
  }

  return password;
}
