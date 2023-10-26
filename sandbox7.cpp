#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long total_length = 0;
    int fake_count = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'F') {
            fake_count++;
        }
        else {
            total_length += fake_count;
        }
    }

    cout << total_length << endl;

    return 0;
}