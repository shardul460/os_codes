#include <iostream>
using namespace std;

int main() {
    int n, m;
    int alloc[10][10], req[10][10];
    int avail[10];
    int finish[10] = {0};

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Request Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> req[i][j];

    cout << "Enter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int ok = 1;

                for (int j = 0; j < m; j++) {
                    if (req[i][j] > avail[j]) {
                        ok = 0;
                        break;
                    }
                }

                if (ok == 1) {
                    for (int j = 0; j < m; j++)
                        avail[j] = avail[j] + alloc[i][j];

                    finish[i] = 1;
                    count++;
                    found = true;
                }
            }
        }

        if (found == false)
            break;
    }

    if (count == n) {
        cout << "No Deadlock";
    } else {
        cout << "Deadlock Exists\n";
        cout << "Deadlocked Processes: ";
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0)
                cout << "P" << i << " ";
        }
    }

    return 0;
}