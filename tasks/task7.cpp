#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string str;
  std::cin >> str;

  bool is_valid = true;

  if (str.length() != 6) {
    is_valid = false;
  }
  else if (!isupper(str[0])) {
    //isupper() проверяет является ли символ прописным.
    is_valid = false;
  }
  else if (!isdigit(str[1]) || !isdigit(str[2]) || !isdigit(str[3])) {
    //isdigit() проверяет является ли символ цифрой.
    is_valid = false;
  }
  else if (!isupper(str[4]) || !isupper(str[5])) {
    is_valid = false;
  }
  std::cout << (is_valid ? "Yes" : "No") << "\n";
  return 0;
}