#ifndef PASSWORD_GENERATOR_HPP
#define PASSWORD_GENERATOR_HPP

#include <string>

class PasswordGenerator {
public:
  PasswordGenerator();
  
  std::string generatePassword(int length, const std::string& characters);
};

#endif // PASSWORD_GENERATOR_HPP
