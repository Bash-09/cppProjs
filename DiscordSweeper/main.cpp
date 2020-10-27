#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Mine {
    int num = 0;
    bool mine = false;
};

int main() {
    srand(time(nullptr));

    int x = 10;
    int y = 10;
    int mines = 15;

    cout << "Enter y, x, mines.\n";
    cin >> x >> y >> mines;

    Mine field[x][y];

    for(int i = 0; i < mines; i++){
        while(true){
            int mx = rand()%x;
            int my = rand()%y;

            if(field[mx][my].mine) continue;

            field[mx][my].mine = true;
            for(int nx = -1; nx < 2; nx++) {
                for(int ny = -1; ny < 2; ny++) {
                    if(nx == 0 && ny == 0) continue;
                    if(mx + nx < 0 || mx + nx >= x || my+ny < 0 || my+ny >= y) continue;
                    field[mx+nx][my+ny].num++;
                }
            }
        }
    }


    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {

            if(field[i][j].mine) {
                cout << "||:x:||";
            } else {
                switch(field[i][j].num) {
                    case 0:
                        cout << "||:zero:||";
                        break;
                    case 1:
                        cout << "||:one:||";
                        break;
                    case 2:
                        cout << "||:two:||";
                        break;
                    case 3:
                        cout << "||:three:||";
                        break;
                    case 4:
                        cout << "||:four:||";
                        break;
                    case 5:
                        cout << "||:five:||";
                        break;
                    case 6:
                        cout << "||:six:||";
                        break;
                    case 7:
                        cout << "||:seven:||";
                        break;
                    case 8:
                        cout << "||:eight:||";
                        break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
