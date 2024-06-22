#include<bits/stdc++.h>
using namespace std;
void drawboard(char *spaces);
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
char checkwinner(char *spaces,char player,char computer);
bool checktie(char *spaces);
int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running = true;
    srand(time(0));
    drawboard(spaces);
    while(running){
        playermove(spaces,player);
        drawboard(spaces);
        if(checkwinner(spaces,player,computer)==player){
            cout<<"winner player"<<endl;
            break;
        }
        if(checktie(spaces)){
            cout<<"tie "<<endl;
            break;
        }
        computermove(spaces,computer);
        drawboard(spaces);
        if(checkwinner(spaces,player,computer)==computer){
            cout<<"winner computer"<<endl;
            break;
        }
        if(checktie(spaces)){
            cout<<"tie "<<endl;
            break;
        }
    }
    return 0;
}
void drawboard(char *spaces){
    cout<<"   |   |   \n";
    cout<<" "<<spaces[0]<<" | "<<spaces[1]<<" | "<<spaces[2]<<" \n";
    cout<<"---|---|---\n";
    cout<<"   |   |   \n";
    cout<<" "<<spaces[3]<<" | "<<spaces[4]<<" | "<<spaces[5]<<" \n";
    cout<<"---|---|---\n";
    cout<<" "<<spaces[6]<<" | "<<spaces[7]<<" | "<<spaces[8]<<" \n";
    cout<<"   |   |   \n";
    cout<<'\n';
}
void playermove(char *spaces,char player){
    int n;
    do {
        cout << "Enter a number between 1 to 9 for respective block of tic-tac-toe board: ";
        cin >> n;
    } while (n < 1 || n > 9 || spaces[n - 1] != ' ');
    spaces[n-1]=player;
}
void computermove(char *spaces,char computer){
    int n;
    do{
    n=rand()%9;
    }while(spaces[n]!=' ');
    spaces[n]=computer;
}
char checkwinner(char *spaces,char player,char computer){
    if ((spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player)) {
        return player;
    }
    if ((spaces[0] == computer && spaces[1] == computer && spaces[2] == computer) ||
        (spaces[3] == computer && spaces[4] == computer && spaces[5] == computer) ||
        (spaces[6] == computer && spaces[7] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[3] == computer && spaces[6] == computer) ||
        (spaces[1] == computer && spaces[4] == computer && spaces[7] == computer) ||
        (spaces[2] == computer && spaces[5] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[4] == computer && spaces[8] == computer) ||
        (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer)) {
        return computer;
    }
    return ' ';
}
bool checktie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return 0;
        }
    }
    return true;
}