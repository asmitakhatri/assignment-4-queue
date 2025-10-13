#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q, firstHalf;
    int n, val;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    
    for (int i = 0; i < n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }


    while (!firstHalf.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();

        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    return 0;
}