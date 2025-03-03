#include <iostream>
#include <chrono>
#include <cstdlib>


using namespace std;

void heapify(float a[], int n, int i)
{
    int biggest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && a[left] > a[biggest]) biggest = left;
    if (right < n && a[right] > a[biggest]) biggest = right;
    if (biggest != i)
    {
        swap(a[i], a[biggest]);
        heapify(a, n, biggest);
    }
}
void HeapSort(float a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    freopen("test_9.inp", "r", stdin);
    freopen("test_9.out", "w", stdout);

    int n = 500000;
    float a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto start = chrono::steady_clock::now();
    HeapSort(a, n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Runtime: " << chrono::duration <double> (diff).count() << " seconds" << endl;

    for(int i = 0; i < n; ++i) cout << a[i] << endl;
    return 0;
}