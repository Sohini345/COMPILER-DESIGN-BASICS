#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

class Parser {
private:
    std::string input;
    size_t pos;

    // Helper to get the current character
    char peek() {
        if (pos < input.length())
            return input[pos];
        return '\0'; // end of input
    }

    // Helper to consume and move to the next character
    char get() {
        return pos < input.length() ? input[pos++] : '\0';
    }

    // Skip any whitespace
    void skipWhitespace() {
        while (std::isspace(peek()))
            get();
    }

    // Parse a number (integer)
    double parseNumber() {
        skipWhitespace();
        std::string number;
        while (std::isdigit(peek()) || peek() == '.') {
            number += get();
        }
        if (number.empty()) {
            throw std::runtime_error("Expected number at position " + std::to_string(pos));
        }
        return std::stod(number);
    }

    // Parse a factor: number or (expression)
    double parseFactor() {
        skipWhitespace();
        if (peek() == '(') {
            get(); // consume '('
            double result = parseExpression();
            skipWhitespace();
            if (get() != ')') {
                throw std::runtime_error("Expected ')' at position " + std::to_string(pos));
            }
            return result;
        } else {
            return parseNumber();
        }
    }

    // Parse term: factor [ |/ factor ]
    double parseTerm() {
        double result = parseFactor();
        while (true) {
            skipWhitespace();
            char op = peek();
            if (op == '*' || op == '/') {
                get(); // consume operator
                double rhs = parseFactor();
                if (op == '*')
                    result *= rhs;
                else {
                    if (rhs == 0)
                        throw std::runtime_error("Division by zero");
                    result /= rhs;
                }
            } else {
                break;
            }
        }
        return result;
    }

    // Parse expression: term [ +|- term ]*
    double parseExpression() {
        double result = parseTerm();
        while (true) {
            skipWhitespace();
            char op = peek();
            if (op == '+' || op == '-') {
                get(); // consume operator
                double rhs = parseTerm();
                if (op == '+')
                    result += rhs;
                else
                    result -= rhs;
            } else {
                break;
            }
        }
        return result;
    }

public:
    double evaluate(const std::string& expr) {
        input = expr;
        pos = 0;
        double result = parseExpression();
        skipWhitespace();
        if (pos != input.length()) {
            throw std::runtime_error("Unexpected characters at end of expression");
        }
        return result;
    }
};

int main() {
    std::string line;
    Parser parser;

    std::cout << "Simple Arithmetic Expression Evaluator\n";
    std::cout << "Enter expressions like (3 + 4) * 2 - 1 / 5\n";
    std::cout << "Type 'exit' to quit.\n\n";

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, line);
        if (line == "exit")
            break;

        try {
            double result = parser.evaluate(line);
            std::cout << "Result: " << result << "\n\n";
        } catch (const std::exception& ex) {
            std::cout << "Error: " << ex.what() << "\n\n";
        }
    }

    return 0;
}
