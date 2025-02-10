#include <iostream>
#include <limits>

int main() {
  int number;

  while (true) {
    std::cout << "Enter an integer: ";
    try {
      if (std::cin.peek() == ' ' || std::cin.peek() == '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Incorrect input! Please enter a number "
                                 "without a floating point or space.");
      }

      std::cin >> number;

      if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error(
            "Incorrect input! Please enter a number, not a letter.");
      }

      if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Incorrect input! Please enter a number "
                                 "without a floating point or space.");
      }

      if (number <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error(
            "Incorrect input! Please enter a positive number.");
      }

      break;

    } catch (const std::runtime_error &ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

  std::cout << "You have entered a number: " << number << std::endl;

  return 0;
}
