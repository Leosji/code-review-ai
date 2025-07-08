#include <iostream>
#include "PasswordGenerator.h"

int main() {
  PasswordGenerator passwordGen;

  // Определение наборов символов для каждого уровня сложности
  std::string easyChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string mediumChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  std::string hardChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";

  std::cout << "Выберите уровень сложности (1 - Лёгкий, 2 - Средний, 3 - Сложный): ";
  
  int choice;
  std::cin >> choice;

  int length;
  std::string characters;

  switch (choice) {
    case 1:
      length = 8;
      characters = easyChars;
      break;
    case 2:
      length = 12;
      characters = mediumChars;
      break;
    case 3:
      length = 16;
      characters = hardChars;
      break;
    default:
      std::cout << "Некорректный выбор!\n";
      return 1;
  }

  // Генерация пароля
  std::string password = passwordGen.generatePassword(length, characters);
  std::cout << "Ваш сгенерированный пароль: " << password << std::endl;

  return 0;
}
