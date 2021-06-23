#include <iostream>
#include <sstream>

bool check_number(std::string num) {
    int l = num.length() - 1;
    bool point = false;
    for (int i = 0; i <= l; ++i) {
        if (num[i] < '-' || num[i] > '9' || num[i] == '/' || (num[i] == '.' && point) || (num[i] == '-' && i > 0)) {
            return false;
        } else if (num[i] == '.') {
            point = true;
        }
    }
    return true;
}

int point_pos(std::string num) {
    int l = num.length();
    for (int i = 0; i < l; ++i) {
        if (num[i] == '.') {
            return i;
        }
    }
    return l;
}

int part(std::string num, int startPoint, int endPoint){
    std::string partNumStr = "";
    int sign = 1;
    if (num[startPoint] == '-') {
        sign = -1;
        ++startPoint;
    }
    for (int i = startPoint; i < endPoint; ++i) {
        partNumStr += num[i];
    }
    return std::stoi(partNumStr) * sign;
}

std::string fracPart (std::string full, int point) {
    int l = full.length() - 1;
    std::string partFrac = "";
    if (point <= l) {
        for (int i = point + 1; i <= l; ++i) {
            partFrac += full[i];
        }
        return partFrac;
    } else {
        return ("0");
    }
}

std::string equalParts (std::string part, int l) {
    while (part.length() < l) {
        part += '0';
    }
    return part;
}

std::string compare(std::string one, std::string two) {
    int pointOne = point_pos(one);
    int pointTwo = point_pos(two);
    std::string oneFracStr = fracPart(one, pointOne);
    std::string twoFracStr = fracPart(two, pointTwo);
    if (oneFracStr.length() < twoFracStr.length()) {
        oneFracStr = equalParts(oneFracStr, twoFracStr.length());
    } else if (oneFracStr.length() > twoFracStr.length()) {
        twoFracStr = equalParts(twoFracStr, oneFracStr.length());
    }
    int oneInt = part(one, 0, pointOne);
    int oneFrac = 0;
    if (pointOne != one.length()) {
        oneFrac = part(oneFracStr, 0, oneFracStr.length());
    }
    if (oneInt < 0) {
        oneFrac = -oneFrac;
    }
    int twoInt = part(two, 0, pointTwo);
    int twoFrac = 0;
    if (pointTwo != two.length()) {
        twoFrac = part(twoFracStr, 0, twoFracStr.length());
    }
    if (twoInt < 0) {
        twoFrac = -twoFrac;
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
