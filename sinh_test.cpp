#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {
    int size = 500000;
    vector <vector <float>> test(10, vector <float>(size));

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-500.0, 500.0); 

    // Day tang dan
    for (int i = 0; i < size; ++i) {
        test[0][i] = dis(gen);
    }
    sort(test[0].begin(), test[0].end());

    // Day giam dan
    for (int i = 0; i < size; ++i) {
        test[1][i] = dis(gen);
    }
    sort(test[1].rbegin(), test[1].rend());

    // Ngau nhien
    for (int i = 2; i < 10; ++i) {
        for (int j = 0; j < size; ++j) {
            test[i][j] = dis(gen);
        }
    }

    // Ghi vao file
    for (int i = 1; i <= 10; ++i) {
        ofstream outFile("test_" + to_string(i) + ".inp");
        if (outFile.is_open()) {
            for (float val : test[i-1]) {
                outFile << val << endl;
            }
            outFile.close();
        }
    }

    cout << "Done!" << endl;

    return 0;
}