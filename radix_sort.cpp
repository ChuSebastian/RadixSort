#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; 
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void file_input(int arr[], int n, string filename) {
    int i = 0;
    arr[n];

    ifstream file (filename);

    if (file.is_open()) {
        while (!file.eof()) {
            file >> arr[i];
            i++;
        }
    }
}
 
int main() {
    int n = 100000;
    int arr[n];
    file_input(arr, n, "100k.txt"); // range from 1 to 10000000 digits
    radixSort(arr, n);
    print(arr, n);
    return 0;
}