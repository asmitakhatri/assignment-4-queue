#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    queue<char> q;

    cout << "Output: ";
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        q.push(ch);

        
        while (!q.empty()) {
            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == q.front()) count++;
            }
            if (count > 1) {
                q.pop();  
            } else {
                break; 
            }
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;

    return 0;
}