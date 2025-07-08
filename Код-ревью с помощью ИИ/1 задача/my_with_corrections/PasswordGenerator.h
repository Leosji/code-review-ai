#pragma once


#include <string>
#include <stdexcept>

class PasswordGenerator
{
public:
  // Перечисление уровней сложности пароля
  enum class ComplexityLevel
  {
    Simple = 1,
    Medium,
    Strong       
  };

  // Основной метод для генерации пароля заданного уровня сложности
  // При некорректном уровне может выбросить исключение
  std::string generatePassword(int level);

private:
  // Проверяет, входит ли переданный уровень в допустимый диапазон
  bool isValidComplexityLevel(int level) const;

  // Возвращает набор символов, соответствующий уровню сложности
  std::string getCharsetForLevel(int level) const;

  // Возвращает длину пароля, соответствующую уровню сложности
  size_t getPasswordLengthForLevel(int level) const;

  // Генерирует случайный символ из переданного набора символов
  char generateRandomChar(const std::string& charset) const;
};
