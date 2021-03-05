/*
题目：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3
*/

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int A, B;
    cin >> A >> B;
    int min, max;
    if (A > B) {
        max = A;
        min = B;
    } else {
        max = B;
        min = A;
    }
    int tmp = max;
    while (max % min) {
        max += tmp;
    }
    cout << max << endl;
    return 0;
}