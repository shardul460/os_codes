#include <iostream>
using namespace std;

void paging() {
    int pageSize;
    int pageTable[5] = {5, 9, 1, 3, 7};

    cout << "\n--- PAGING ---\n";

    cout << "Enter Page Size: ";
    cin >> pageSize;

    int logical;
    cout << "Enter Logical Address: ";
    cin >> logical;

    int page = logical / pageSize;
    int offset = logical % pageSize;

    int frame = pageTable[page];
    int physical = frame * pageSize + offset;

    cout << "Page Number = " << page << endl;
    cout << "Offset = " << offset << endl;
    cout << "Frame Number = " << frame << endl;
    cout << "Physical Address = " << physical << endl;
}

void segmentation() {
    int base[3] = {1000, 2000, 3000};
    int limit[3] = {500, 400, 600};

    cout << "\n--- SEGMENTATION ---\n";

    int seg, offset;

    cout << "Enter Segment Number: ";
    cin >> seg;

    cout << "Enter Offset: ";
    cin >> offset;

    if (offset < limit[seg]) {
        int physical = base[seg] + offset;
        cout << "Base Address = " << base[seg] << endl;
        cout << "Physical Address = " << physical << endl;
    } else {
        cout << "Invalid Address (Segmentation Fault)" << endl;
    }
}

int main() {
    paging();
    segmentation();
    return 0;
}