#pragma once
#include <initializer_list>
#include <string>
#include <sstream>

template <typename T>
class Stack {
private:
    T* data;
    int length;
    int capacity;
    T* top_;
    void reallocate() {
        if (capacity == 0) {
            delete data;
            data = new T[1];
            top_ = data - 1;
            capacity = 1;
        }
        else {
            int new_index = top_ - data;
            T* new_data = new T[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                new_data[i] = data[i];
            }
            delete data;
            data = new_data;
            top_ = new_data + new_index;
            capacity *= 2;
        }
    }
public:
    Stack() : length(0), top_(nullptr), capacity(0) {
        data = new T;
    };
    int size() const {
        return length;
    }
    void push(int value) {
        if (length == capacity) {
            reallocate();
        };
        data[length] = value;
        top_++;
        length++;
    };
    void pop() {
        top_--;
        length--;
    }
    bool isEmpty() {
        return length == 0;
    }
    T top() {
        return *top_;
    }
    ~Stack() {
        delete data;
    }
    void operator>>(T& value) {
        value = top();
        pop();
    }
    void operator<<(int value) {
        push(value);
    }
    Stack& operator=(const std::initializer_list<int>& list) {
        while (!isEmpty())
            pop();
        std::initializer_list<int>::iterator it = list.begin();
        for (it; it != list.end(); it++) {
            push(*it);
        }
        return *this;
    }
    bool operator<(const Stack<T>& stack) const {
        return size() < stack.size();
    }
    bool operator>(const Stack<T>& stack) const {
        return size() > stack.size();
    }
    bool operator==(const Stack<T>& stack) const {
        if (size() != stack.size()) return false;
        for(int i =0; i < size(); i++){
            if(*(data+ i) != *(stack.data + i)) return false;
        }
        return true;
    }
    T& operator[](int index) {
        //do you even understand what are you making us to do??? kvadratnie skobochki v steke eto cho....
        return *(data + index);
    }
};

namespace calculator {
    std::string input_memory;
    std::string current_kurwed;

    void processExpression(const std::string& expression) {
        input_memory = expression;
    };

    bool isExpressionCorrect(const std::string& expression) {
        Stack<char> brackets;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '(') brackets.push('(');
            if (expression[i] == ')') {
                if (brackets.isEmpty() || brackets.top() != '(') {
                    return false;
                }
                else {
                    brackets.pop();
                }
            }
        };
        if (!brackets.isEmpty()) return false;
        // ////////////////////////////////// //
        if (!isdigit(expression[0]) && expression[0] != '-' && expression[0] != '(') return false;
        if (!isdigit((expression[expression.size() - 1])) && expression[expression.size() - 1] != ')') return false;
        if (expression.size() == 1 && !isdigit(expression[0])) return false;
        for (int i = 1; i < expression.size() - 1; i++) {
            bool right_side_digit = false, left_side_digit = false, right_is_bracket = false, left_is_bracket = false;
            //
            int j = i - 1;
            while (j > -1 && expression[j] == ' ') {
                j--;
            }
            if (isdigit(expression[j])) left_side_digit = true;
            else if (expression[j] == ')') left_is_bracket = true;

            j = i + 1;
            while (j < expression.size() && expression[j] == ' ') {
                j++;
            }
            if (isdigit(expression[j])) right_side_digit = true;
            else if (expression[j] == '(') right_is_bracket = true;
            //
            if (expression[i] == ' ') {
                if (right_side_digit && left_side_digit) return false;
                if (!right_side_digit && !left_side_digit) {
                    if ((left_is_bracket && right_is_bracket) || (!left_is_bracket && !right_is_bracket))
                        return false;
                }
                continue;
            }
            else
            if (expression[i] == '-') {
                if (!right_side_digit && !left_side_digit) return false;
                if (!right_side_digit && left_side_digit) {
                    if (expression[j] != '-')
                        return false;
                }
                continue;
            }
            else
            if (expression[i] == '(' || expression[i] == ')') {
                if (right_side_digit && left_side_digit) return false;
                continue;
            }
            else
            if (!isdigit(expression[i])) {
                if (!right_side_digit && !left_side_digit) {
                    if(!right_is_bracket && !left_is_bracket)
                        return false;
                }
                if (right_side_digit && !left_side_digit && expression[j] != '-') {
                    if(!left_is_bracket)
                        return false;
                }
                continue;
            };
        };
        return true;
    };

    int calculateResult(const std::string &kurwed_expression = current_kurwed) {
        Stack<int> numbers;
        Stack<char> operations;
        std::stringstream buffer(kurwed_expression);
        std::string temp;
        while (buffer >> temp) {
            if (temp.length() > 1) {
                if (isdigit(temp[0]))
                    numbers.push(std::stoi(temp));
                else numbers.push(-std::stoi(temp.substr(1, temp.length() - 1)));
            }
            if (temp.length() == 1)
                if (temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/') {
                    int num1, num2;
                    num2 = numbers.top();
                    numbers.pop();
                    num1 = numbers.top();
                    numbers.pop();
                    switch (temp[0]) {
                        case '+':
                            numbers.push(num1 + num2);
                            break;
                        case '-':
                            numbers.push(num1 - num2);
                            break;
                        case '*':
                            numbers.push(num1 * num2);
                            break;
                        case '/':
                            numbers.push(num1 / num2);
                            break;
                    }
                }
                else {
                    numbers.push(std::stoi(temp));
                }
        };
        return numbers.top();
    };

    int get_priority(char symbol) {
        switch (symbol) {
            case '+':
                return 2;
            case '-':
                return 2;
            case '*':
                return 3;
            case '/':
                return 3;
            default:
                return 0;
        }
    }

    std::string kurwa(std::string expression = input_memory) {
        expression += " ";
        std::string result;
        Stack<char> operations;
        bool previous_element_is_operation = true;
        int length = expression.length();
        int i = 0;
        while (i < length) {
            if (expression[i] >= '0' && expression[i] <= '9') {
                int substr_int_ind_begin = i;
                while (expression[i] >= '0' && expression[i] <= '9') {
                    if (i < length - 1)
                        i++;
                    else break;
                }
                if (i == substr_int_ind_begin) {
                    result += expression[i];
                    result += ",";
                    i++;
                }
                else
                    result += expression.substr(substr_int_ind_begin, i - substr_int_ind_begin) + ",";
                previous_element_is_operation = false;
            }

            if (expression[i] == ' ') i++;

            if (expression[i] == '+' ||
                expression[i] == '-' ||
                expression[i] == '*' ||
                expression[i] == '/') {
                if (!previous_element_is_operation) {
                    previous_element_is_operation = true;
                    if (!operations.isEmpty()) {
                        if (get_priority(expression[i]) == get_priority(operations.top())) {
                            result += operations.top();
                            result += ",";
                            operations.pop();
                            operations.push(expression[i]);
                        }
                        else if (get_priority(expression[i]) > get_priority(operations.top())) {
                            operations.push(expression[i]);
                        }
                        else if (get_priority(expression[i]) < get_priority(operations.top())) {
                            while (get_priority(expression[i]) < get_priority(operations.top()) && !operations.isEmpty()) {
                                result += operations.top();
                                result += ",";
                                operations.pop();
                            }
                            operations.push(expression[i]);
                        }
                        i++;
                        continue;
                    }
                    else {
                        operations.push(expression[i]);
                        i++;
                        continue;
                    }
                }
                else {
                    i++;
                    while (expression[i] == ' ') i++;
                    int substr_int_ind_begin = i;
                    while (expression[i] >= '0' && expression[i] <= '9') {
                        if (i < length - 1)
                            i++;
                        else break;
                    }
                    if (i == substr_int_ind_begin) {
                        result += expression[i];
                        result += ",";
                        i++;
                    }
                    else {
                        result += "-" + expression.substr(substr_int_ind_begin, i - substr_int_ind_begin);
                        result += ",";
                    };
                    previous_element_is_operation = false;
                    continue;
                }
            }
            if (expression[i] == '(') {
                operations.push(expression[i]);
                i++;
                previous_element_is_operation = true;
                continue;
            }
            if (expression[i] == ')') {
                while (operations.top() != '(') {
                    result += operations.top();
                    result += ",";
                    operations.pop();
                }
                operations.pop();
                i++;
                previous_element_is_operation = false;
                continue;
            }
        }
        while (!operations.isEmpty()) {
            result += operations.top();
            result += ",";
            operations.pop();
        }
        if (!result.empty()) result.erase(result.size() - 1);
        for (int k = 0; k < result.size(); k++) {
            if (result[k] == ',') result[k] = ' ';
        }
        current_kurwed = result;
        return result;
    };

};
