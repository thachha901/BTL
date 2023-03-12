#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#define MAX 4

using namespace std;

char a[3][3] = {'1', '2', '3', '4', '5', '6', '7','8','9'};

struct Toado{
    int x;
    int y;
};
//Ve ban co
void veBanCo(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//Nguoi choi nhap X
void getPlayerX(){
    cout << "Player X's turn" << endl;
    Toado toado;
    cout << "Nhap x: ";
    cin >> toado.x ;
    cout << "Nhap y: ";
    cin >> toado.y;
    cout << endl;
    if(a[toado.x][toado.y] != 'O'){
        a[toado.x][toado.y] = 'X';
    }else{
        cout << "Error! Please retype your choice :3" << endl;
        Toado toado;
        cout << "Nhap x: ";
        cin >> toado.x ;
        cout << "Nhap y: ";
        cin >> toado.y;
        cout << endl;
        if(a[toado.x][toado.y] != 'O'){
            a[toado.x][toado.y] = 'X';
        }
        while(a[toado.x][toado.y] == 'O'){
            cout << "Error! Please retype your choice :3" << endl;
            cout << "Nhap x: ";
            cin >> toado.x ;
            cout << "Nhap y: ";
            cin >> toado.y;
            if(a[toado.x][toado.y] != 'O'){
                a[toado.x][toado.y] = 'X';
            }
            cout << endl;
        }
    }
}
//Nguoi choi nhap O
void getPlayerO(){
    cout << "Player O's turn" << endl;
    Toado toado;
    cout << "Nhap x: ";
    cin >> toado.x ;
    cout << "Nhap y: ";
    cin >> toado.y;
    cout << endl;
    if(a[toado.x][toado.y] != 'X'){
        a[toado.x][toado.y] = 'O';
    }else{
        cout << "Error! Please retype your choice :3" << endl;
        Toado toado;
        cout << "Nhap x: ";
        cin >> toado.x ;
        cout << "Nhap y: ";
        cin >> toado.y;
        if(a[toado.x][toado.y] != 'X'){
            a[toado.x][toado.y] = 'O';
        }
        cout << endl;
        while(a[toado.x][toado.y] == 'X'){
            cout << "Error! Please retype your choice :3" << endl;
            cout << "Nhap x: ";
            cin >> toado.x ;
            cout << "Nhap y: ";
            cin >> toado.y;
            if(a[toado.x][toado.y] != 'X'){
                a[toado.x][toado.y] = 'O';
            }
            cout << endl;
        }
    }
}
//Kiem tra nguoi choi thang
bool checkWin(){
    if((a[0][0] == a[0][1] && a[0][0] == a[0][2]) || (a[1][0] == a[1][1] && a[1][0] == a[1][2]) || (a[2][0] == a[2][1] && a[2][0] == a[2][2])){
        return 1;
    }
    if((a[0][0] == a[1][0] && a[2][0] == a[0][0]) || (a[0][1] == a[1][1] && a[1][1] == a[2][1]) || (a[0][2] == a[1][2] && a[0][2] == a[2][2])){
        return 1;
    }
    if((a[0][0] == a[1][1] && a[0][0] == a[2][2]) || (a[0][2] == a[1][1] && a[1][1] == a[2][0])){
        return 1;
    }
    return 0;
}
//In ra ket qua tro choi
void resultOfTheGame(){
    if(checkWin()){
        cout << "You Win";
    }
}

int main(int argc, char* argv[]){
    veBanCo();
    while(!checkWin()){
        getPlayerX();
        getPlayerO();
        veBanCo();
    }
    return 0;
}
