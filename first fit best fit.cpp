#include <iostream>
using namespace std;

int block[] = {100, 500, 200, 300, 600};
int process[] = {212, 417, 112, 426};

int m = 5;
int n = 4;

void firstFit() {
    int b[5];
    for(int i = 0; i < m; i++)
        b[i] = block[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[j] >= process[i]) {
                b[j] = b[j] - process[i];
                break;
            }
        }
    }

    cout << "First Fit Done" << endl;
}

void bestFit() {
    int b[5];
    for(int i = 0; i < m; i++)
        b[i] = block[i];

    for(int i = 0; i < n; i++) {
        int pos = -1;

        for(int j = 0; j < m; j++) {
            if(b[j] >= process[i]) {
                if(pos == -1 || b[j] < b[pos])
                    pos = j;
            }
        }

        if(pos != -1)
            b[pos] = b[pos] - process[i];
    }

    cout << "Best Fit Done" << endl;
}

void worstFit() {
    int b[5];
    for(int i = 0; i < m; i++)
        b[i] = block[i];

    for(int i = 0; i < n; i++) {
        int pos = -1;

        for(int j = 0; j < m; j++) {
            if(b[j] >= process[i]) {
                if(pos == -1 || b[j] > b[pos])
                    pos = j;
            }
        }

        if(pos != -1)
            b[pos] = b[pos] - process[i];
    }

    cout << "Worst Fit Done" << endl;
}

void nextFit() {
    int b[5];
    for(int i = 0; i < m; i++)
        b[i] = block[i];

    int pos = 0;

    for(int i = 0; i < n; i++) {
        int count = 0;

        while(count < m) {
            if(b[pos] >= process[i]) {
                b[pos] = b[pos] - process[i];
                break;
            }

            pos = (pos + 1) % m;
            count++;
        }
    }

    cout << "Next Fit Done" << endl;
}

int main() {
    firstFit();
    bestFit();
    worstFit();
    nextFit();
    return 0;
}