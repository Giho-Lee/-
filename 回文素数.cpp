/*
题目：https://leetcode-cn.com/problems/prime-palindrome/
*/


class Solution {
public:
    int isPrime (int N) {
        if (N < 2)
            return false;
        int tmp = (int)sqrt(N);
        for (int i = 2; i <= tmp; i++) {
            if (0 == N % i)
                return false;
        }
        return true;
    }

    int isReverse(int N) {
        int tmp = N;
        int result = 0;
        while (tmp) {
            result = result * 10 + (tmp % 10);
            tmp /= 10;
        }

        return N == result;
    }
    int primePalindrome(int N) {
        for (;;) {
            if (isReverse(N) && isPrime(N)) {
                return N;
            }
            N++;
        }
    }
};