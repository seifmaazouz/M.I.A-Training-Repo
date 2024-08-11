#include <iostream>
// #include <bits/stdc++.h>

using namespace std;


void sort(int arr[], int n);
void swap(int *x, int *y);
float maximum(float x, float y);

int main() {

    int n, l;
    cout << "Number of lanterns: ";
    cin >> n;
    cout << "Length of street: ";
    cin >> l;

    int lanterns[n];
    cout << "Position of "<< n << " Lanterns: ";
    for (int i = 0; i < n; i++) {
        cin >> lanterns[i];
    }

    sort(lanterns, n);
    float d = maximum((lanterns[0] - 0), (l - lanterns[n-1]));
    for (int i = 0; i < n-1; i++) {
        d = maximum((lanterns[i+1] - lanterns[i])/2.0, d);
    }


    printf("Minimum light radius: %.2f", d);

    return 0;
}

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        for(int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

float maximum(float x, float y) {
    return x > y ? x : y;
}
