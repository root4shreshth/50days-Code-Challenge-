#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_CHARS 128

char* min(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);    
    if (s_len == 0 || t_len == 0 || s_len < t_len) {
        return "";
    }    
    int t_freq[MAX_CHARS] = {0};
    int freq[MAX_CHARS] = {0};    
    for (int i = 0; i < t_len; i++) {
        t_freq[t[i]]++;
    }    
    int req = 0;
    for (int i = 0; i < MAX_CHARS; i++) {
        if (t_freq[i] > 0) {
            req++;
        }
    }    
    int left = 0, right = 0;
    int x = 0;
    int min_len = INT_MAX;
    int min_left = 0;    
    while (right < s_len) {
        char c = s[right];
        freq[c]++;        
        if (t_freq[c] > 0 && freq[c] == t_freq[c]) {
            x++;
        }        
        while (left <= right && x == req) {
            c = s[left];            
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }            
            freq[c]--;
            if (t_freq[c] > 0 && freq[c] < t_freq[c]) {
                x--;
            }           
            left++;
        }        
        right++;
    }    
    if (min_len == INT_MAX) {
        return "";
    }    
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + min_left, min_len);
    result[min_len] = '\0';    
    return result;
}
int main() {
    char s[100001];
    char t[100001];    
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';    
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';    
    char* result = min(s, t);
    printf("%s\n", result);
    
    free(result);
    return 0;
}