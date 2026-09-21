#include <iostream>
using namespace std;

int main() {
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

    return 0;
}
