#include <iostream>
using namespace std;

int block[] = {100, 500, 200, 300, 600};
int process = 212;
int m = 5;

void firstFit() {
    int pos = -1;

    for (int j = 0; j < m; j++) {
        if (block[j] >= process) {
            pos = j;
            break;
        }
    }

    cout << "\nFirst Fit\n";

    if (pos != -1)
        cout << "Process " << process
             << " -> Block " << pos + 1
             << " (" << block[pos] << ")" << endl;
    else
        cout << "Not Allocated" << endl;
}

void bestFit() {
    int pos = -1;

    for (int j = 0; j < m; j++) {
        if (block[j] >= process) {
            if (pos == -1 || block[j] < block[pos])
                pos = j;
        }
    }

    cout << "\nBest Fit\n";

    if (pos != -1)
        cout << "Process " << process
             << " -> Block " << pos + 1
             << " (" << block[pos] << ")" << endl;
    else
        cout << "Not Allocated" << endl;
}

void worstFit() {
    int pos = -1;

    for (int j = 0; j < m; j++) {
        if (block[j] >= process) {
            if (pos == -1 || block[j] > block[pos])
                pos = j;
        }
    }

    cout << "\nWorst Fit\n";

    if (pos != -1)
        cout << "Process " << process
             << " -> Block " << pos + 1
             << " (" << block[pos] << ")" << endl;
    else
        cout << "Not Allocated" << endl;
}

void nextFit() {
    int pos = 0;
    int count = 0;
    int allocated = 0;

    while (count < m) {
        if (block[pos] >= process) {
            allocated = 1;
            break;
        }

        pos = (pos + 1) % m;
        count++;
    }

    cout << "\nNext Fit\n";

    if (allocated)
        cout << "Process " << process
             << " -> Block " << pos + 1
             << " (" << block[pos] << ")" << endl;
    else
        cout << "Not Allocated" << endl;
}

int main() {
    firstFit();
    bestFit();
    worstFit();
    nextFit();
    return 0;
}
