#include <iostream>
#include <chrono>
#include <cstdlib>


using namespace std;

void merge(float a[], int left, int mid, int right)
{
    int m = left;
    int n = mid+1;
    int k = 0;
    float* temp = new float[right-left+1];
    
    while (m <= mid && n <= right) {
        float nextValue;
 
        if (a[m] < a[n]) nextValue = a[m++];
        else nextValue = a[n++];
 
        temp[k++] = nextValue;
    }
 
    while (m <= mid) temp[k++] = a[m++];
    while (n <= right) temp[k++] = a[n++];
 
    for (int i = 0; i < k; i++) a[left + i] = temp[i];
    delete[] temp;
}

void MergeSort(float a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    freopen("test_3.inp", "r", stdin);
    freopen("test_3.out", "w", stdout);
    int n = 500000;
    float a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];

    auto start = chrono::steady_clock::now();
    MergeSort(a, 0, n-1);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Runtime: " << chrono::duration <double> (diff).count() << " seconds" << endl;

    for(int i = 0; i < n; ++i) cout << a[i] << endl;
    return 0;
}