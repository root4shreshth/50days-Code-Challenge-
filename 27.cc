#include <iostream>
#include <vector>
using namespace std;
int cnt_path(int row, int col){
    if (row == 0 || col == 0)
        return 0;
    vector<vector<int>> pathcount(row, vector<int>(col, 1));
    for (int i = 1; i < row; ++i){
        for (int j = 1; j < col; ++j){
            pathcount[i][j] = pathcount[i - 1][j] + pathcount[i][j - 1];
        }
    }
    return pathcount[row - 1][col - 1];
}
int main(){
    int g_row, g_col;
    cin >> g_row >> g_col;
    cout << cnt_path(g_row, g_col) << endl;
    return 0;
}