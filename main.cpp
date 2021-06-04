#include <iostream>
#include <sstream>

bool check_number(std::string num) {
    int l = num.length() - 1;
    bool point = false;
    for (int i = 0; i <= l; ++i) {
        if (num[i] < 45 || num[i] > 57 || num[i] == 47 || (num[i] == 46 && point) || (num[i] == 45 && i > 0)) {
            return false;
        } else if (num[i] == 46) {
            point = true;
        }
    }
    return true;
}

int point_pos(std::string num) {
    int l = num.length();
    for (int i = 0; i < l; ++i) {
        if (num[i] == 46) {
            return i;
        }
    }
    return l;
}

int part(std::string num, int startPoint, int endPoint){
    std::string partNumStr = "";
    int sign = 1;
    if (num[startPoint] == 45) {
        sign = -1;
        ++startPoint;
    }
    for (int i = startPoint; i < endPoint; ++i) {
        partNumStr += num[i];
    }
    return std::stoi(partNumStr) * sign;
}

std::string compare(std::string one, std::string two) {
    int oneInt = part(one, 0, point_pos(one));
    int oneFrac = 0;
    if (point_pos(one) != one.length()) {
        oneFrac = part(one, point_pos(one) + 1, one.length());
    }
    if (oneInt < 0) {
        oneFrac *= -1;
    }
    int twoInt = part(two, 0, point_pos(two));
    int twoFrac = 0;
    if (point_pos(two) != two.length()) {
        twoFrac = part(two, point_pos(two) + 1, two.length());
    }
    if (twoInt < 0) {
        twoFrac *= -1;
    }
    if (oneInt > twoInt || (oneInt == twoInt && oneFrac > twoFrac)) {
        return "More";
    } else if (oneInt < twoInt || (oneInt == twoInt && oneFrac < twoFrac)) {
        return "Less";
    } else {
        return "Equal";
    }
}

int main() {
    std::string numberOne;
    std::cout << "Input the first number: ";
    std::cin >> numberOne;
    while (!check_number(numberOne)) {
        std::cout << "Wrong input. Try again: ";
        std::cin >> numberOne;
    }

    std::string numberTwo;
    std::cout << "Input the second number: ";
    std::cin >> numberTwo;
    while (!check_number(numberTwo)) {
        std::cout << "Wrong input. Try again: ";
        std::cin >> numberTwo;
    }

    std::cout << compare(numberOne, numberTwo);
    return 0;
}
