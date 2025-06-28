#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s; // Stack to store the elements
    int minVal;   // Variable to keep track of the minimum element

public:
    // fn to push
    void push(int val) { // Tc - O(1)
        if (s.empty()) {
            s.push(val);
            minVal = val; // Initialize minVal with the first pushed value
        } else {
            if (val < minVal) { // If new value is smaller than current min
                s.push(2 * val - minVal); // Encode it to preserve previous min
                minVal = val;             // Update minVal to new minimum
            } else {
                s.push(val); // Push normally if it's not less than minVal
            }
        }
    }

    // fn to top
    int top() { // Tc - O(1)
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        if (s.top() < minVal) {
            // If encoded value is on top, return current min
            return minVal;
        } else {
            return s.top(); // Otherwise return the actual top
        }
    }

    // fn to pop
    void pop() { // Tc - O(1)
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        if (s.top() < minVal) {
            // If encoded value is on top, decode previous minVal
            minVal = 2 * minVal - s.top();
        }
        s.pop(); // Pop the top element
    }

    // fn to get the min value in constant time
    int getMin() { // Tc - O(1)
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return minVal; // Return the current minVal
    }
};

int main() {
    MinStack s;

    // Push sequence
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Top element: " << s.top() << endl;          // Should print 2
    cout << "Minimum element: " << s.getMin() << endl;   // Should print 2

    s.pop(); // Remove the top element (2)

    cout << "Top element: " << s.top() << endl;          // Should print 7
    cout << "Minimum element: " << s.getMin() << endl;   // Should print 3

    return 0;
}