#include <iostream>

int globalInts[] = {6, 7, 8, 9, 10};

void changeInt(int a) { // (int& a) responds differently
    a++;
}

void changeArr(int d[]) {
    d[2] = 8;
    d = globalInts;
}

void printArr(int e[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << e[i] << std::endl;
    }
}

int main() {
    int b = 5;
    int c[] = {1, 2, 3, 4, 5};
    int size = 5;
    std::cout << "Here is size: " << size << std::endl;

    changeInt(b);
    changeArr(c);

    std::cout << "Here is b: " << b << std::endl;
    std::cout << "Here is c: " << std::endl;
    printArr(c, size);
    return 0;
}