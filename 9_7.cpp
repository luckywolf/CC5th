#include <iostream>
#include <cstdio>
using namespace std;

enum color{
    red, yellow, blue, green
};

bool paint_fill(color screen[][5], int m, int n, int x, int y, color c){
    if(x < 0 || x >= m || y < 0 || y >= n) return false;
    if(screen[x][y] == c) return false;
    else{
        screen[x][y] = c;
        paint_fill(screen, m, n, x-1, y, c);
        paint_fill(screen, m, n, x+1, y, c);
        paint_fill(screen, m, n, x, y-1, c);
        paint_fill(screen, m, n, x, y+1, c);
    }
    return true;
}
int main(){
//    int m = 5, n = 5
//    color **screen = new color*[m];
//    for(int i = 0; i < 5; ++i)
//        screen[i] = new color[n];
//    for(int i = 0; i < 5; ++i)
//        for(int j = 0; j < n; ++j){
//            int t;
//            cin>>t;
//            screen[i][j]=(color)t;
//        }
    
    color screen[5][5] = {
         {red, green, green, blue, yellow},
         {green, red, yellow, green, green},
         {green, green, red, blue, green},
         {red, green, green, green, yellow},
         {red, yellow, red, blue, yellow}
    };
    paint_fill(screen, 5, 5, 1, 2, green);
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j)
            cout << screen[i][j]<<" ";
        cout << endl;
    }
    return 0;
}