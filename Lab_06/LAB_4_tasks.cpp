#include <iostream>
using namespace std;

// ============================================================
// Task 4: Hostel room occupancy tracker (3 floors x 3 rows x 4 rooms)
// ============================================================
void task4() {
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
}

// ============================================================
// Task 5: Lab computers in-use tracker (2 labs x 3 rows x 5 computers)
// ============================================================
void task5() {
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
}

// ============================================================
// Task 6: Search a 3D array (2 layers x 2 rows x 2 columns)
// ============================================================
void task6() {
    int a[2][2][2] = {
        {
            {11, 22},
            {33, 44}
        },
        {
            {55, 66},
            {77, 88}
        }
    };

    int v;
    bool found = false;

    for (int i = 0; i < 2; i++) {
        cout << "Layer " << i + 1 << ":\n";

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << a[i][j][k] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    cout << "Enter value to search: ";
    cin >> v;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {

                if (a[i][j][k] == v) {
                    cout << "Found\n";
                    cout << "Layer: " << i + 1 << endl;
                    cout << "Row: " << j + 1 << endl;
                    cout << "Column: " << k + 1 << endl;

                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "Not found";
    }
}

// ============================================================
// Main menu
// ============================================================
int main() {
    int choice;

    cout << "===== LAB 4 =====\n";
    cout << "1. Task 4 - Hostel Rooms Tracker\n";
    cout << "2. Task 5 - Lab Computers Tracker\n";
    cout << "3. Task 6 - 3D Array Search\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            task4();
            break;
        case 2:
            task5();
            break;
        case 3:
            task6();
            break;
        default:
            cout << "Invalid choice.";
    }

    return 0;
}
