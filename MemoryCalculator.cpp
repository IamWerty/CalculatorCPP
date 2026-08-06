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
        case '+': memory += value; break;
        case '-': memory -= value; break;
        case '*': memory *= value; break;
        case '/':
            if (value != 0)
                memory /= value;
            else
				throw std::invalid_argument("Division by zero");
            break;
        default:
            throw std::invalid_argument("Invalid operation");
        }
        return memory;
    }
    Calculator& calculate(char operation, int value) {
        calculateInt(operation, value);
        return *this;
	}
    Calculator& operator-(int value) { return calculate('-', value);}
	Calculator& operator+(int value) { return calculate('+', value); }
	Calculator& operator*(int value) { return calculate('*', value); }
	Calculator& operator/(int value) { return calculate('/', value); }
	Calculator& operator=(int value) { setMemory(value); return *this; }
	Calculator& operator+=(int value) { return calculate('+', value); }
	Calculator& operator-=(int value) { return calculate('-', value); }
	Calculator& operator*=(int value) { return calculate('*', value); }
	Calculator& operator/=(int value) { return calculate('/', value); }


    int getMemory() const {
        return memory;
    }
};

int main()
{
    Calculator calc = 10;
	int result = calc.calculate('+', 5).calculate('-', 15).getMemory();
    calc + 5 * 10;
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