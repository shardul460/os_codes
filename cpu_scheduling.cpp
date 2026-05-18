#include <iostream>
#include <algorithm>
using namespace std;

int bt[] = {5, 3, 8, 6};
int pr[] = {2, 1, 4, 3};
int n = 4;

void fcfs() {
    int wt[4], tat[4];
    int avgWT = 0, avgTAT = 0;

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    cout << "\nFCFS\n";
    cout << "P\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "Average WT = " << (float)avgWT / n << endl;
    cout << "Average TAT = " << (float)avgTAT / n << endl;
}

void sjf() {
    int b[4], wt[4], tat[4];
    int avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
        b[i] = bt[i];

    sort(b, b + n);

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + b[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + b[i];

    cout << "\nSJF\n";
    cout << "BT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << b[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "Average WT = " << (float)avgWT / n << endl;
    cout << "Average TAT = " << (float)avgTAT / n << endl;
}

void priority() {
    int b[4], p[4], wt[4], tat[4];
    int avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        b[i] = bt[i];
        p[i] = pr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + b[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + b[i];

    cout << "\nPriority Scheduling\n";
    cout << "Priority\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t\t" << b[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "Average WT = " << (float)avgWT / n << endl;
    cout << "Average TAT = " << (float)avgTAT / n << endl;
}

void roundRobin() {
    int rem[4], wt[4] = {0}, tat[4];
    int tq = 2;
    int time = 0;
    int avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
        rem[i] = bt[i];

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;

                if (rem[i] > tq) {
                    time = time + tq;
                    rem[i] = rem[i] - tq;
                } else {
                    time = time + rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    cout << "\nRound Robin\n";
    cout << "P\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "Average WT = " << (float)avgWT / n << endl;
    cout << "Average TAT = " << (float)avgTAT / n << endl;
}

int main() {
    fcfs();
    sjf();
    priority();
    roundRobin();
    return 0;
}