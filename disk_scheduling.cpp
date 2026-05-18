#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = 8, head = 53, seek = 0;


    seek = 0;
    int cur = head;

    for (int i = 0; i < n; i++) {
        seek += abs(req[i] - cur);
        cur = req[i];
    }

    cout << "FCFS = " << seek << endl;


    int vis[10] = {0};
    seek = 0;
    cur = head;

    for (int i = 0; i < n; i++) {
        int idx = -1, mn = 1e9;

        for (int j = 0; j < n; j++) {
            if (!vis[j] && abs(req[j] - cur) < mn) {
                mn = abs(req[j] - cur);
                idx = j;
            }
        }

        vis[idx] = 1;
        seek += abs(req[idx] - cur);
        cur = req[idx];
    }

    cout << "SSTF = " << seek << endl;


    int arr[10];

    for (int i = 0; i < n; i++)
        arr[i] = req[i];

    sort(arr, arr + n);

    seek = 0;
    cur = head;

    int i;

    for (i = 0; i < n; i++)
        if (arr[i] > head)
            break;

    for (int j = i; j < n; j++) {
        seek += abs(arr[j] - cur);
        cur = arr[j];
    }

    for (int j = i - 1; j >= 0; j--) {
        seek += abs(arr[j] - cur);
        cur = arr[j];
    }

    cout << "SCAN = " << seek << endl;


    seek = 0;
    cur = head;

    for (int j = i; j < n; j++) {
        seek += abs(arr[j] - cur);
        cur = arr[j];
    }

    cur = 0;

    for (int j = 0; j < i; j++) {
        seek += abs(arr[j] - cur);
        cur = arr[j];
    }

    cout << "C-SCAN = " << seek << endl;
}