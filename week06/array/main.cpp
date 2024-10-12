//
// Created by stg05 on 12.10.2024.
//


#include <iostream>

template<typename T, typename P>
T pow(T param, P pow) {
    T result = param;
    if (!std::is_integral_v<P>) {
        throw std::invalid_argument{"Unsupported type of the 2nd operand"};
    }
    for (P i = 0; i < pow - 1; i++) {
        result *= param;
    }
    return result;
}

template<typename T>
T pow(T param, char pow) {
    throw std::invalid_argument{"Unsupported type of the 2nd operand"};
}

int main() {
    std::cout << pow(1.1, 'a');
    return 0;
}
