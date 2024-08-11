#include <iostream>

using namespace std;

// int search(int arr[], int n, int target) {
//     for(int i = 0; i < n; i++) {
//         if(arr[i] == target) {
//             return i;
//         }
//     }
//     return -1;
// }

int binSearch(int arr[], int n, int target) {
    int start = 0, end = n, mid;
    mid = (start + end)/2;
    while(start <= end) {
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            start = mid + 1;
        else  
            end = mid - 1;
    }
}


int main() {
    
    int n, target;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    cout << binSearch(arr, n , target);
    
    return 0;
}