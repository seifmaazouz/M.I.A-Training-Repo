#include <iostream>

using namespace std;

int main() {

    int n, k;
    cout << "Number of tasks: ";
    cin >> n;
    cout << "Number of minutes needed for flash to get to base: ";
    cin >> k;

    int maxTasks = 0,  time = k;
    for(int i = 1; i <= n; i++) {
        time += i*5;
        if(time > 4*60)
            break;
        maxTasks++;
    }

    printf("Maximum number of tasks that can be completed: %d", maxTasks);

    return 0;
}