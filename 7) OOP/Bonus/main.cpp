#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class customQueue {
    private:
        stack<string> stack1;
        stack<string> stack2;
    public:
        void Enqueue(string str) {
            stack1.push(str);
        }
        string dequeue() {
            if(stack1.empty() && stack2.empty())
            {
                return "Queue is Empty";
            }

            if(stack2.empty()) // check if there is no items in stack 2
            {
                while(!stack1.empty()) // reverse order of stack by poping all contents of stack1 to stack2
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            string firstItem = stack2.top(); // obtain first item added to stack
            stack2.pop(); // remove item after dequeueing from stack
            return firstItem;
        }
        void display() {
            if(stack1.empty() && stack2.empty())
                printf("Queue is Empty");
            else 
            {
                printf("Queue: ");
                while(!stack2.empty()) // display items in stack2 which is reversed order of stack1
                {
                    cout << stack2.top();
                    stack2.pop();
                    if(!stack1.empty() || !stack2.empty()) // don't add , at the end of queue
                        cout << ", ";
                }
                if(!stack1.empty()) 
                {
                    while(!stack1.empty()) // reverse order of stack by poping all contents of stack1 to stack2
                    {
                        stack2.push(stack1.top());
                        stack1.pop();
                    }
                    while(!stack2.empty()) // display items in stack2 which is reversed order of stack1
                    {
                        cout << stack2.top();
                        stack2.pop();
                        if(!stack1.empty() || !stack2.empty()) // don't add , at the end of queue
                            cout << ", ";
                    }
                }
            }
            cout << endl;
        }
};


int main() {

    string batmanWeapons[4] = {"Batarang", "Grapple Gun", "Explosive Gel", "Batclaw"};
    string batmanShields[2] = {"Cape Glide", "Smoke Pellet"};

    customQueue weaponsQueue;
    customQueue shieldaQueue;

    // to show queue is empty
    weaponsQueue.display();
    shieldaQueue.display();

    for(auto weapon:batmanWeapons) // fill weaponsQueue with the weapons array above
    {
        weaponsQueue.Enqueue(weapon);
    }

    for(auto shield:batmanShields)  // fill shieldsQueue with the shields array above
    {
        shieldaQueue.Enqueue(shield);
    }

    // display both queues
    weaponsQueue.display();
    shieldaQueue.display();

    return 0;
}