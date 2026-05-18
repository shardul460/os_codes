#include <iostream>
using namespace std;

int main() {
    int total, size, block = 1;

    cout << "Enter total memory: ";
    cin >> total;

    cout << "Enter required size: ";
    cin >> size;

    while (block < size) {
        block = block * 2;
    }

    if (block > total) {
        cout << "Allocation Failed\n";
        return 0;
    }

    cout << "Allocated Block = " << block << endl;
    cout << "Internal Fragmentation = " << block - size << endl;

    cout << "Deallocating Block." << endl;
    cout << "Buddy blocks merged." << endl;
    cout << "Memory Freed Successfully." << endl;

    return 0;
}