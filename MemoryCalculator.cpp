#include <iostream>

class Calculator
{
private:
    int memory;
public:
	Calculator(int initialMemory){
        memory = initialMemory;
    }
    Calculator() {
        memory = 0;
	}
    ~Calculator() {
        std::cout << "Calculator destroyed\n";
	}
    void setMemory(int value) {
        memory = value;
    }
    int calculateInt(char operation, int value) {
        switch (operation)
        {
        case '+':
            memory += value;
            break;
        case '-':
            memory -= value;
            break;
        case '*':
            memory *= value;
            break;
        case '/':
            if (value != 0)
                memory /= value;
            else
                std::cout << "Error: Division by zero\n";
            break;
        default:
            std::cout << "Error: Invalid operation\n";
        }
        return memory;
    }
    int getMemory() {
        return memory;
    }
};

int main()
{
    Calculator calc = 10;
	bool doWhile = true;
	std::cout << "Memory Calculator\n";
    std::cout << "Current Memory: " << calc.getMemory() << "\n";
	std::cout << "Setting memory: ";
	int value;
	std::cin >> value;
	calc.setMemory(value);
    while (doWhile) {
		std::cout << "\nCurrent Memory: " << calc.getMemory() << "\n";
		std::cout << "Enter operation (+, -, *, /) or 'q' to quit: ";
        char operation;
        std::cin >> operation;
        if (operation == 'q') {
            doWhile = false;
            break;
        } else {
            std::cout << "Enter value: ";
            int value;
            std::cin >> value;
            calc.calculateInt(operation, value);
        }
    }
}