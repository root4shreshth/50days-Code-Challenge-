#include <stdio.h>
#include <stdlib.h>

int cnt_path(int row, int col) {    
    if (row == 0 || col == 0) return 0;   
    int **pathcount = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        pathcount[i] = (int *)malloc(col * sizeof(int));}    
    for (int i = 0; i < row; i++) {
        pathcount[i][0] = 1;}
    for (int j = 0; j < col; j++) {
        pathcount[0][j] = 1;}    
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            pathcount[i][j] = pathcount[i-1][j] + pathcount[i][j-1];
        }
    }    
    int result = pathcount[row-1][col-1];    
    for (int i = 0; i < row; i++) {
        free(pathcount[i]);
    }
    free(pathcount);    
    return result;
}
int main(){
    int g_row, g_col;
    scanf("%d %d", &g_row, &g_col);
    printf("%d\n", cnt_path(g_row, g_col));
    return 0;
}