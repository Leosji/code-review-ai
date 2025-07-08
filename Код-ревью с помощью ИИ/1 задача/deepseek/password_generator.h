#pragma once

#include <string>

class PasswordGenerator {
public:
  // Генерирует пароль заданного уровня сложности
  // Уровни: 1 - простой, 2 - средний, 3 - сложный
  std::string generatePassword(int complexityLevel);

private:
  // Проверяет валидность уровня сложности
  bool isValidComplexityLevel(int level) const;
  
  // Возвращает набор символов для генерации пароля
  std::string getCharsetForLevel(int level) const;
  
  // Возвращает длину пароля для уровня сложности
  int getPasswordLengthForLevel(int level) const;
};
