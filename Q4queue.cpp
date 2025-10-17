#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;              
    unordered_map<char, int> freq; 
    for (char ch : str) {
        freq[ch]++;        
        q.push(ch);        

    
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

       
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
}

int main() {
    string input = "aaabbcc"; 
    firstNonRepeating(input);
    return 0;
}
