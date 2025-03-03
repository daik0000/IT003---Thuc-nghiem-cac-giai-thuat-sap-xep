#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>


using namespace std;

int partition(float a[], int left, int right)
{
    float pivot = a[right];
    int id = left - 1;
    for (int i = left; i < right; i++)
    {
        if (a[i] < pivot)
        {
            id++;
            swap(a[id], a[i]);
        }
    }
    id++;
    swap(a[id], a[right]);
    return id;
}
void QuickSort(float a[], int left, int right)
{
    if (left < right)
    {
        int id_pivot = partition(a, left, right);
        QuickSort(a, left, id_pivot-1);
        QuickSort(a, id_pivot+1, right);
    }
}

int main()
{
    freopen("test_10.inp", "r", stdin);
    freopen("test_10.out", "w", stdout);

    int n = 500000;
    float a[n];
        
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto start = chrono::steady_clock::now();
    QuickSort(a, 0, n-1);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Runtime: " << chrono::duration <double> (diff).count() << " seconds" << endl;

    for(int i = 0; i < n; ++i) cout << a[i] << endl;

    return 0;
}