#include <iostream>

using namespace std;

int maximum(int x, int y);

int main() {
    
    int n;
    cout << "Number of cards: ";
    cin >> n;

    cout << "Enter the numbers on the cards from left to right (distinct):\n";
    int cards[n];
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int max, batman = 0, joker = 0;
    int l = 0, r = n-1;
    for (int i = 0; i < n; i++) {
        max = maximum(cards[l], cards[r]);
        if (i%2 == 0)
            batman += max;
        else 
            joker += max;

        if (max == cards[l])
            l++;
        else
            r--;
    }

    printf("Batman: %d\tJoker: %d", batman, joker);

    return 0;
}

int maximum(int x, int y) {
    return x > y ? x : y;
}
