/*
题目: https://www.nowcoder.com/practice/de538edd6f7e4bc3a5689723a7435682
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    char str[40] = {0};
    char *chp = NULL;
    int A, B, C, D, E, wrong, private_ip;
    A = B = C = D = E = wrong = private_ip = 0;
    while (scanf("%s", &str) != EOF) {
        chp = str;
        unsigned ip = 0;
        unsigned ipArr[8] = {0};
        unsigned k = 0;
        int i = 0;
        int badVal = 0;
        int newLine = 0;
        for (;;) {
            switch (*chp) {
                case '0'...'9':
                {
                    ip = ip * 10 + ((*chp) - '0'); // 计算IP值
                    i++;
                    break;
                }
                case '\0':
                {
                    newLine = 1; // 该行处理结束
                }
                case '.':
                case '~':
                {
                    if (0 <= ip && ip <= 255) {
                        ipArr[k++] = ip;
                        ip = 0;
                        i = 0;
                    } else {
                        badVal = 1;
                    }
                    break;
                }
                default: {
                    badVal = 1;
                    break;
                }
            }
            if (badVal || newLine) 
                break;
            chp++;
        }

_badValue:        
        if (badVal) {
            wrong++;
            continue;
        }
        
        if ((255 == ipArr[0] && 255 == ipArr[1] && 255 == ipArr[2] && 255 == ipArr[3]) 
        || (0 == ipArr[0] && 0 == ipArr[1] && 0 == ipArr[2] && 0 == ipArr[3])
        || (255 == ipArr[4] && 255 == ipArr[5] && 255 == ipArr[6] && 255 == ipArr[7]) 
        || (0 == ipArr[4] && 0 == ipArr[5] && 0 == ipArr[6] && 0 == ipArr[7])
        ) {
            badVal = 1;
            goto _badValue;
        }
        
        unsigned char flag = 0;
        for (int j = 4; j < 8; j++) {
            for (int t = 7;  t >= 0; t--) {
                if (0 == (unsigned char)(ipArr[j] & (1 << t))) {
                    flag = 1;
                } else if (flag) {
                    badVal = 1;
                    goto _badValue;
                }
            }
        }
              
        if (1 <= ipArr[0] && ipArr[0] <= 126) {
            A++;
            if (10 == ipArr[0]) {
                private_ip++;
            }
        } else if (128 <= ipArr[0] && ipArr[0] <= 191) {
            B++;
            if (172 == ipArr[0] && (16 <= ipArr[1] && ipArr[1] <= 31)) {
                private_ip++;
            }
        } else if (192 <= ipArr[0] && ipArr[0] <= 223) {
            C++;
            if (192 == ipArr[0] && 168 == ipArr[1]) {
                private_ip++;
            }
        } else if (224 <= ipArr[0] && ipArr[0] <= 239) {
            D++;
        } else if (240 <= ipArr[0] && ipArr[0] <= 255) {
            E++;
        }
    }
    
    printf ("%u %u %u %u %u %u %u\n", A, B, C, D, E, wrong, private_ip);
    
    return 0;
}