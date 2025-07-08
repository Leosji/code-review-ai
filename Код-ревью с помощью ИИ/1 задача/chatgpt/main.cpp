#include "passwordGenerator.h"
#include <iostream>
#include <stdexcept>

int main()
{
  try
  {
    int difficultyLevel;

    std::cout << "Выберите уровень сложности пароля:\n";
    std::cout << "1 - Лёгкий (только строчные буквы, длина 6)\n";
    std::cout << "2 - Средний (буквы и цифры, длина 10)\n";
    std::cout << "3 - Сложный (буквы, цифры, символы, длина 16)\n";
    std::cout << "Введите 1, 2 или 3: ";
    std::cin >> difficultyLevel;

    if (difficultyLevel < 1 || difficultyLevel > 3)
    {
      throw std::invalid_argument("Ошибка: уровень сложности должен быть от 1 до 3.");
    }

    std::string password = generatePassword(difficultyLevel);

    std::cout << "\nСгенерированный пароль: " << password << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Исключение: " << e.what() << std::endl;
  }

  return 0;
}
