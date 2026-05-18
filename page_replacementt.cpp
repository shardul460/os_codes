#include <iostream>
using namespace std;

int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
int n = 13, f = 3;

void fifo() {
    int frame[3] = {-1,-1,-1};
    int pos = 0, faults = 0;

    for(int i = 0; i < n; i++) {
        int hit = 0;

        for(int j = 0; j < f; j++)
            if(frame[j] == pages[i])
                hit = 1;

        if(!hit) {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }

    cout << "FIFO faults = " << faults << endl;
}

void lru() {
    int frame[3] = {-1,-1,-1};
    int recent[3] = {-1,-1,-1};
    int faults = 0;

    for(int i = 0; i < n; i++) {
        int hit = 0;

        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                hit = 1;
                recent[j] = i;
            }
        }

        if(!hit) {
            int pos = 0;

            for(int j = 1; j < f; j++)
                if(recent[j] < recent[pos])
                    pos = j;

            frame[pos] = pages[i];
            recent[pos] = i;
            faults++;
        }
    }

    cout << "LRU faults = " << faults << endl;
}

void optimal() {
    int frame[3] = {-1,-1,-1};
    int faults = 0;

    for(int i = 0; i < n; i++) {
        int hit = 0;

        for(int j = 0; j < f; j++)
            if(frame[j] == pages[i])
                hit = 1;

        if(!hit) {
            int pos = 0, farthest = -1;

            for(int j = 0; j < f; j++) {
                int k;

                for(k = i + 1; k < n; k++)
                    if(frame[j] == pages[k])
                        break;

                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }
    }

    cout << "Optimal faults = " << faults << endl;
}

int main() {
    fifo();
    lru();
    optimal();
    return 0;
}