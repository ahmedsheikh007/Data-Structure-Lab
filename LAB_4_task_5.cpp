#include <iostream>
using namespace std;

int main() {
    int c[2][3][5] = {
        {
            {0, 0, 1, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 0, 0, 1}
        },
        {
            {1, 0, 1, 0, 1},
            {0, 0, 1, 1, 0},
            {1, 1, 0, 0, 0}
        }
    };

    int available = 0;
    int inUse = 0;
    int labAvailable[2] = {0, 0};
    int x, y, z;
    for (int i = 0; i < 2; i++) {
        cout << "Lab " << i + 1 << ":\n";

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 5; k++) {
                cout << c[i][j][k] << " ";

                if (c[i][j][k] == 0) {
                    available++;
                    labAvailable[i]++;
                } else {
                    inUse++;
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    cout << "Available = " << available << endl;
    cout << "In Use = " << inUse << endl;

    cout << "Lab 1 available = " << labAvailable[0] << endl;
    cout << "Lab 2 available = " << labAvailable[1] << endl;
    cout << "\nEnter lab, row, and computer: ";
    cin >> x >> y >> z;

    if (c[x - 1][y - 1][z - 1]) {
        cout << "In Use";
    } else {
        cout << "Available";
    }

    return 0;
}
