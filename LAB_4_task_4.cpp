#include <iostream>
using namespace std;

int main() {
    int b[3][3][4] = {
        {
            {0, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 1}
        },
        {
            {1, 1, 0, 0},
            {0, 0, 1, 0},
            {1, 0, 1, 1}
        },
        {
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 0, 0}
        }
    };

    int occupied = 0;
    int floorOccupied[3] = {0, 0, 0};
    int x, y, z;
    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1 << ":\n";

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << b[i][j][k] << " ";

                if (b[i][j][k]) {
                    occupied++;
                    floorOccupied[i]++;
                }
            }

            cout << endl;
        }

        cout << endl;
    }
    cout << "Occupied = " << occupied << endl;
    cout << "Available = " << 36 - occupied << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1
             << " occupied = " << floorOccupied[i] << endl;
    }
    cout << "\nEnter floor, row, and room: ";
    cin >> x >> y >> z;

    if (b[x - 1][y - 1][z - 1]) {
        cout << "Occupied";
    } else {
        cout << "Available";
    }

    return 0;
}
