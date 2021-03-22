//
//  main.cpp
//  BitManipulation
//
//  Created by Gabriel Robinson on 3/20/21.
//

#include <iostream>

void swapIntsWithoutTemp(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void swapIntsWithTemp(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void testSwapInt() {
    int length = 25;
    for (int i = 0; i < 25; i++) {
        int x1 = i, x2 = i, y1 = length - i, y2 = length - i;
        swapIntsWithoutTemp(x1, y1);
        swapIntsWithTemp(x2, y2);
        assert(x1 == x2);
        assert(y1 == y2);
    }
}

bool isEven(int x) {
    return x % 2 == 0;
}

bool isEvenBitManipulation(int x) {
    return !(x & 1);
}

void testIsEven() {
    for (int i = 0; i < 25; i++) {
        bool x1 = isEven(i);
        bool x2 = isEvenBitManipulation(i);
        assert(x1 == x2);
    }
}

bool haveOppositeSigns(int x, int y) {
    // if the XOR of x and y is negative then they have opposite signs
    return (x ^ y) < 0;
}

void turnOffKthBit(int &n, int k) {
    int x = ~(1 << (k - 1));
    n = n & x;
}

bool kthBitIsSet(int n, int k) {
    return (n >> (k - 1)) & 1;
}

void testKthBitIsSet() {
    int n = 20;
    int k = 3;
    if (kthBitIsSet(n, k)) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test failed" << std::endl;
    }
}

void turnOnKthBit(int &n, int k) {
    int x = 1 << (k - 1);
    n = n | x;
}

void toggleKthBit(int &n, int k) {
    int x = 1 << (k - 1);
    n = n ^ x;
}

void testHaveOppositeSigns() {
    assert(haveOppositeSigns(-1, 1) == true);
    assert(haveOppositeSigns(1, 1) == false);
    assert(haveOppositeSigns(-1, -1) == false);
    assert(haveOppositeSigns(1, -1) == true);
}

void unsetRightMostBit(int &n) {
    n = n & (n - 1);
}

bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}

void testIsPowerOfTwo() {
    int i = 1;
    for (; i <= 4096; i *= 2) {
        assert(isPowerOfTwo(i));
    }
    std::cout << "Test passed" << std::endl;
}

int positionOfRightMostSetBit(int n) {
    int position = 1;
        
    while(!(n & 1)) {
        n = n >> 1;
        position++;
    }
    
    return position;
}

void testPositionOfRightMostSetBit() {
    assert(positionOfRightMostSetBit(1) == 1);
    assert(positionOfRightMostSetBit(2) == 2);
    assert(positionOfRightMostSetBit(4) == 3);
    assert(positionOfRightMostSetBit(8) == 4);
    assert(positionOfRightMostSetBit(16) == 5);
    assert(positionOfRightMostSetBit(32) == 6);
    assert(positionOfRightMostSetBit(64) == 7);
    assert(positionOfRightMostSetBit(128) == 8);
    std::cout << "Test passed" << std::endl;
}

int positionOfSetBit(int n) {
    if (n & (n - 1)) {
        std::cout << "Incorrect input." << std::endl;
        return -1;
    }
    
    return log2(n) + 1;
}

bool findParity(unsigned int n) {
    bool parity = false;
    
    while(n) {
        
        if (n & 1)
            parity = !parity;
        
        n = n >> 1;
    }
    
    return parity;
}

std::string toLowercase(std::string s) {
    std::string lowercaseS = "";
    for (int i = 0; i < s.size(); i++) {
        int charValue = int(s[i]);
        if (charValue >= 65 && charValue <= 90) {
            char newChar = charValue + 32;
            lowercaseS += newChar;
        } else {
            lowercaseS += charValue;
        }
    }
    return lowercaseS;
}

std::string toUppercase(std::string s) {
    std::string lowercaseS = "";
    for (int i = 0; i < s.size(); i++) {
        int charValue = int(s[i]);
        if (charValue >= 97 && charValue <= 122) {
            char newChar = charValue - 32;
            lowercaseS += newChar;
        } else {
            lowercaseS += charValue;
        }
    }
    return lowercaseS;
}

std::string invertString(std::string s) {
    std::string lowercaseS = "";
    for (int i = 0; i < s.size(); i++) {
        int charValue = int(s[i]);
        lowercaseS += charValue ^ ' ';
    }
    return lowercaseS;
}

int getPositionInAlphabet(char letter) {
    return 'A' & 31;
}


int main(int argc, const char * argv[]) {
//    testSwapInt();
//    std::cout << "Test passed\n" << std::endl;
//    testIsEven();
//    std::cout << "Test passed\n" << std::endl;
//    testHaveOppositeSigns();
//    std::cout << "Test passed\n" << std::endl;
//    int n = 20, k = 3;
//    turnOffKthBit(n, k);
//    assert(n == 16);
//    std::cout << "Test passed\n" << std::endl;
//    turnOnKthBit(n, k);
//    assert(n == 20);
//    std::cout << "Test passed\n" << std::endl;
//    testKthBitIsSet();
//    testIsPowerOfTwo();
//    testPositionOfRightMostSetBit();
//    std::cout << toLowercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ") << std::endl;
    std::cout << invertString("aBcDeFgHiJkLmNoPqRsTuVwXyZ") << std::endl;
    return 0;
}

