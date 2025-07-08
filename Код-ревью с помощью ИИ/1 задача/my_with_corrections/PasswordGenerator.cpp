#include "PasswordGenerator.h"
#include <random>
#include <algorithm>

namespace
{
  // Набор символов для различных категорий:
  const std::string kLowercase = "abcdefghijklmnopqrstuvwxyz";
  const std::string kUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const std::string kDigits = "0123456789";
  const std::string kSymbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

  // Возвращает ссылку на статический генератор случайных чисел Mersenne Twister,
  // инициализированный случайным устройством (random_device) при первом вызове.
  // Используем static, чтобы не создавать генератор заново при каждом вызове.
  // chat gpt
  std::mt19937& getRandomGenerator()
  {
    static std::random_device rd; // аппаратный источник случайности
    static std::mt19937 gen(rd()); // генератор псевдослучайных чисел
    return gen;
  }
}

bool PasswordGenerator::isValidComplexityLevel(int level) const
{
  // Проверяем, что уровень сложности входит в диапазон определенных уровней enum ComplexityLevel
  return level >= static_cast<int>(ComplexityLevel::Simple) &&
         level <= static_cast<int>(ComplexityLevel::Strong);
}
//deepseek
std::string PasswordGenerator::getCharsetForLevel(int level) const
{
  // В зависимости от уровня сложности возвращаем соответствующий набор символов
  switch (static_cast<ComplexityLevel>(level))
  {
    case ComplexityLevel::Simple:
    {
      // Для простого уровня - только буквы (строчные и заглавные)
      return kLowercase + kUppercase;
    }
    case ComplexityLevel::Medium:
    {
      // Для среднего - буквы + цифры
      return kLowercase + kUppercase + kDigits;
    }
    case ComplexityLevel::Strong:
    {
      // Для высокого уровня - буквы + цифры + спецсимволы
      return kLowercase + kUppercase + kDigits + kSymbols;
    }
    default:
    {
      // Если уровень некорректен, возвращаем пустую строку
      return "";
    }
  }
}
//deepseek
size_t PasswordGenerator::getPasswordLengthForLevel(int level) const
{
  // Возвращаем длину пароля, зависящую от сложности
  switch (static_cast<int>(level))
  {
    case static_cast<int>(ComplexityLevel::Simple):
    {
      return 10; // простой - 10 символов
    }
    case static_cast<int>(ComplexityLevel::Medium):
    {
      return 14; // средний - 14 символов
    }
    case static_cast<int>(ComplexityLevel::Strong):
    {
      return 18; // высокий - 18 символов
    }
    default:
    {
      return 0; // при ошибочном уровне длина 0
    }
  }
}

char PasswordGenerator::generateRandomChar(const std::string& charset) const
{
  // Выбираем случайный индекс символа из переданного набора charset
  std::uniform_int_distribution<size_t> dist(0, charset.size() - 1);
  // Возвращаем символ по случайному индексу
  return charset[dist(getRandomGenerator())];
}

std::string PasswordGenerator::generatePassword(int level)
{
  // Проверка корректности уровня сложности
  if (!isValidComplexityLevel(level))
  {
    throw std::invalid_argument("Invalid complexity level");
  }

  // Получаем набор символов и длину пароля для данного уровня
  const std::string charset = getCharsetForLevel(level);
  const size_t length = getPasswordLengthForLevel(level);
  std::string password;
  password.reserve(length); // резервируем память для пароля заранее

  // Формируем пароль случайными символами из набора
  for (size_t i = 0; i < length; ++i)
  {
    password += generateRandomChar(charset);
  }

  // Для уровней Medium и Strong гарантируем наличие обязательных символов

  if (level >= static_cast<int>(ComplexityLevel::Medium))
  {
    // Проверяем, есть ли хотя бы одна цифра, если нет - подменяем случайный символ на цифру
    if (password.find_first_of(kDigits) == std::string::npos)
    {
      std::uniform_int_distribution<size_t> posDist(0, length - 1);
      password[posDist(getRandomGenerator())] = generateRandomChar(kDigits);
    }

    if (level == static_cast<int>(ComplexityLevel::Strong))
    {
      // Для Strong дополнительно проверяем наличие хотя бы одного символа из спецнаборов,
      // если нет - заменяем случайный символ на спецсимвол
      if (password.find_first_of(kSymbols) == std::string::npos)
      {
        std::uniform_int_distribution<size_t> posDist(0, length - 1);
        password[posDist(getRandomGenerator())] = generateRandomChar(kSymbols);
      }
    }
  }

  // Перемешиваем символы пароля, чтобы расположение обязательных символов было случайным
  std::shuffle(password.begin(), password.end(), getRandomGenerator());

  return password;
}
