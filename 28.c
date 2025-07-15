#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_num(char* s) {
    bool x = false;
    bool y = false;
    bool z = false;    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];        
        if (is_digit(c)) {
            x = true;
        } else if (c == '+' || c == '-') {
            if (i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) {
                return false;
            }
        } else if (c == '.') {
            if (y || z) {
                return false;
            }
            y = true;
        } else if (c == 'e' || c == 'E') {
            if (z || !x) {
                return false;
            }
            z = true;
           x = false; // reset for exponent part
        } else {
            return false;
        }
    }    
    return x;
}
int main() {
    char s[21];
    scanf("%20s", s);    
    if (is_num(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }    
    return 0;
}