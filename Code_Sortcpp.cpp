#include <iostream>
#include <chrono>
#include <algorithm>


using namespace std;

int main()
{
    freopen("test_10.inp", "r", stdin);
    freopen("test_10.out", "w", stdout);
    int n = 500000;
    float a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto start = chrono::steady_clock::now();
    
    sort(a, a+n);

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Runtime: " << chrono::duration <double> (diff).count() << " seconds" << endl;
    for(int i = 0; i < n; ++i) cout << a[i] << endl;
    return 0;
}