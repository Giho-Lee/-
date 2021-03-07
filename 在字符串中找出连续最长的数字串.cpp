/*
题目：https://www.nowcoder.com/practice/2c81f88ecd5a4cc395b5308a99afbbec
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    string str;
    while (cin >> str) {
        int n = str.length();
        int maxLen = 0;
        string resultStr = "";
        string dStr = "";
        int len = 0;
        for (int i = 0; i <= n; i++) {
            switch (str[i]) {
                case '0'...'9':
                    len++;
                    dStr.push_back(str[i]);
                    break;
                default:
                    if (len > 0) {
                        if (len > maxLen) {
                            maxLen = len;
                            resultStr = dStr;
                        } else if (len == maxLen) {
                            resultStr += dStr;
                        }
                    }           
                    len = 0;
                    dStr = "";
            }
        }
        cout << resultStr << "," << maxLen << endl;
    }
    return 0;
}