#include <iostream>
using namespace std;

int block[] = {100, 500, 200, 300, 600};
int process[] = {212, 417, 112, 426};

int m = 5;
int n = 4;

void firstFit() {
    int b[5];
    for (int i = 0; i < m; i++)
        b[i] = block[i];

    cout << "\nFirst Fit\n";

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < m; j++) {
            if (b[j] >= process[i]) {
                pos = j;
                break;
            }
        }

        if (pos != -1) {
            cout << "Process " << process[i]
                 << " -> Block " << pos + 1
                 << " (" << b[pos] << ")" << endl;
            b[pos] = b[pos] - process[i];
        } else {
            cout << "Process " << process[i]
                 << " -> Not Allocated" << endl;
        }
    }
}

void bestFit() {
    int b[5];
    for (int i = 0; i < m; i++)
        b[i] = block[i];

    cout << "\nBest Fit\n";

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < m; j++) {
            if (b[j] >= process[i]) {
                if (pos == -1 || b[j] < b[pos])
                    pos = j;
            }
        }

        if (pos != -1) {
            cout << "Process " << process[i]
                 << " -> Block " << pos + 1
                 << " (" << b[pos] << ")" << endl;
            b[pos] = b[pos] - process[i];
        } else {
            cout << "Process " << process[i]
                 << " -> Not Allocated" << endl;
        }
    }
}

void worstFit() {
    int b[5];
    for (int i = 0; i < m; i++)
        b[i] = block[i];

    cout << "\nWorst Fit\n";

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < m; j++) {
            if (b[j] >= process[i]) {
                if (pos == -1 || b[j] > b[pos])
                    pos = j;
            }
        }

        if (pos != -1) {
            cout << "Process " << process[i]
                 << " -> Block " << pos + 1
                 << " (" << b[pos] << ")" << endl;
            b[pos] = b[pos] - process[i];
        } else {
            cout << "Process " << process[i]
                 << " -> Not Allocated" << endl;
        }
    }
}

void nextFit() {
    int b[5];
    for (int i = 0; i < m; i++)
        b[i] = block[i];

    int pos = 0;

    cout << "\nNext Fit\n";

    for (int i = 0; i < n; i++) {
        int count = 0;
        int start = pos;
        int allocated = 0;

        while (count < m) {
            if (b[pos] >= process[i]) {
                cout << "Process " << process[i]
                     << " -> Block " << pos + 1
                     << " (" << b[pos] << ")" << endl;
                b[pos] = b[pos] - process[i];
                allocated = 1;
                break;
            }

            pos = (pos + 1) % m;
            count++;
        }

        if (!allocated) {
            cout << "Process " << process[i]
                 << " -> Not Allocated" << endl;
        }
    }
}

int main() {
    firstFit();
    bestFit();
    worstFit();
    nextFit();
    return 0;
}
