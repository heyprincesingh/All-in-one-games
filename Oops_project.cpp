#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<windows.h>
using namespace std;

void jump(int x,int y){
    static HANDLE h = NULL;
    if(!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y};
    SetConsoleCursorPosition(h,c);
}
void screen();
void box(){
    system("CLS");
    int i;
    char b = 219;
    for(i=0;i<100;i++){
       cout<<b;
   }
   jump(0,1);
   for(i=0;i<=10;i++){
       cout<<b<<"                                                                                                  "<<b<<endl;
   }
   for(i=0;i<100;i++){
       cout<<b;
   }
}
void input(){
    cout<<"Choose your option : ";
}


 //Lottery code starts
void guessnumber_box(){
    box();
    jump(32,2);
    cout<<"----(Lottery - Guess the digit)----";
}
void guessnumber_indicator(int l, bool temp,int dif){
    char a = 205,b = 206,c = 31,d = 23,e = 200,f = 188,g = 186;
    jump(9,9);
    for(int i=9;i<=90;i++){
        if(i==9){ cout<<g; jump(9,10); cout<<e;}
        else if(i==90){ cout<<f; jump(90,9); cout<<g;}
        else if(i==50){
            cout<<b;
            jump(50,9);
            cout<<d;
            jump(51,10);
        }
        else cout<<a;
    }

    if(temp) jump(50+dif,9);
    else jump(50-dif,9);

    cout<<c;
}
void guessnumber_screen(){
    int num,g,count = 1,opt;
    string name;
    srand(time(0));
    num = rand() % 100 + 1;
    guessnumber_box();
    jump(36,4);
    cout<<"Enter your name : ";
    cin>>name;
    guessnumber_box();
    jump(27,4);
    cout<<"Guess random number between 1 - 100!\n\n\t\t\t\t   Choose your guess : ";
    cin>>g;
    while(g!=num){
        count++;
        guessnumber_box();
        jump(80,3);
        if(g>num){
            cout<<"Chances taken : "<<count;
            guessnumber_indicator(g,1,g-num);
            jump(28,6);
            cout<<"Too high! Guess a lower number : ";
        }
        else{
            cout<<"Chances taken : "<<count;
            guessnumber_indicator(g,0,num-g);
            jump(28,6);
            cout<<"Too low! Guess a higher number : ";
        }
        cin>>g;
    }
    init:
    guessnumber_box();
    jump(20,5);
    cout<<"You made it "<<name<<"...It took you "<<count<<" chances to guess it right!";
    jump(40,7);
    cout<<"1. Play again";
    jump(40,8);
    cout<<"2. Exit"; 
    jump(33,10);
    input();
    cin>>opt;
    if(opt == 1) guessnumber_screen();
    else if(opt == 2) screen();
    else goto init;
}
void guessnumber(){
    int l;
    box();
    jump(32,3);
    cout<<"----(Lottery - Guess the digit)----\n\n";
    cout<<"\t\t\t\t\t  1. Play New Game\n\n";
    cout<<"\t\t\t\t\t  2. Exit";
    jump(33,10);
    input();
    cin>>l;
    switch (l)
    {
        case 1:
        guessnumber_screen();
        break;
        case 2:
        screen();
        break;
    
    default:
    guessnumber();
        break;
    }
} //Lottery code over


 //TicTacToe code starts
void tictactoe_restart();
char board[3][3];// = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn = 'x';
bool draw = false;
void tictactoe_box(){
    box();
    jump(38,2);
    cout<<"----( Tic - Tac - Toe )----";
    char a = 186, b = 206, c = 205;
    jump(10,6);
    cout<<"Player 1 : (x)                                                    Player 2 : (o)";
    jump(45,4);
    cout<<" "<<board[0][0]<<" "<<a<<" "<<board[0][1]<<" "<<a<<" "<<board[0][2];
    jump(45,5);
    cout<<c<<c<<c<<b<<c<<c<<c<<b<<c<<c<<c;
    jump(45,6);
    cout<<" "<<board[1][0]<<" "<<a<<" "<<board[1][1]<<" "<<a<<" "<<board[1][2];
    jump(45,7);
    cout<<c<<c<<c<<b<<c<<c<<c<<b<<c<<c<<c;
    jump(45,8);
    cout<<" "<<board[2][0]<<" "<<a<<" "<<board[2][1]<<" "<<a<<" "<<board[2][2];
}
void player_turn(){
    jump(20,10);
    if(turn == 'x'){
        input();
        cout<<"Player - 1 [x] turn : ";
    }
    else if(turn == 'o'){
        input();
        cout<<"Player - 2 [o] turn : ";
    }

    cin>> choice;

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'x' && board[row][column] != 'x' && board[row][column] != 'o'){
        board[row][column] = 'x';
        turn = 'o';
    }else if(turn == 'o' && board[row][column] != 'x' && board[row][column] != 'o'){
        board[row][column] = 'o';
        turn = 'x';
    }else {
        jump(20,11);
        cout<<"Box already filled! Please choose another place!!";
        player_turn();
    }
    tictactoe_box();
}
bool gameover(){
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'x' && board[i][j] != 'o')
    return true;

    draw = true;
    return false;
}
void tictactoe_start(){
    int a = 49;
   for(int i=0;i<3;i++)
      for(int j=0;j<3;j++){
          board[i][j] = a; a++;}
    box();
    while(gameover()){
        tictactoe_box();
        player_turn();
        gameover();
    }
    jump(25,10);
    if(turn == 'x' && draw == false){
        cout<<"Congratulations! Player 2 with 'o' has won the game";
    }
    else if(turn == 'o' && draw == false){
        cout<<"Congratulations! Player 1 with 'x' has won the game";
    }
    else{
        jump(44,10);
        cout<<"GAME DRAW!!!";
    }
    jump(42,11);
    cout<<"(--Press Enter--)";
    getch();
    tictactoe_restart();
}
void tictactoe_restart(){
    int opt;
    box();
    init:
    jump(38,3);
    cout<<"----( Tic - Tac - Toe )----\n\n";
    jump(43,5);
    cout<<"1. Play again";
    jump(43,7);
    cout<<"2. Exit"; 
    jump(36,9);
    input();
    cin>>opt;
    if(opt == 1) tictactoe_start();
    else if(opt == 2) screen();
    else goto init;
}
void tictactoe(){
    int t;
    box();
    jump(38,3);
    cout<<"----( Tic - Tac - Toe )----\n\n";
    cout<<"\t\t\t\t\t  1. Play New Game\n\n";
    cout<<"\t\t\t\t\t  2. Exit\n\n\n\n";
    jump(38,10);
    input();
    cin>>t;
    switch (t)
    {
        case 1:
        tictactoe_start();
        break;

        case 2:
        screen();
        break;
    
        default:
        tictactoe();
        break;
    }
}



void Millionaire(){
    int m;
    box();
    jump(28,3);
    cout<<"----( Millionaire Quizard )----\n\n";
    cout<<"\t\t\t\t  1. Play New Game\n\n";
    cout<<"\t\t\t\t  2. Exit\n\n\n\n";
    jump(33,10);
    input();
    cin>>m;
    switch (m)
    {
    case 2:
        screen();
        break;
    
    default:
        Millionaire();
        break;
    }
}
void screen(){
    int a;
    box();
    jump(32,3);
    cout<<"Welcome to All-in-One Gaming Console\n\n";
    cout<<"\t\t\t\t    1. Lottery - Guess the digit\n";
    cout<<"\t\t\t\t    2. Tic Tac Toe\n";
    cout<<"\t\t\t\t    3. Millionaire Quizard \n";
    cout<<"\t\t\t\t    4. \n";
    cout<<"\t\t\t\t    5. Exit\n\n\n\n";
    jump(33,11);
    input();
    cin>>a;
    switch (a)
    {
    case 1 :
        guessnumber();
        break;
    case 2 :
        tictactoe();
        break;
    case 3 :
        Millionaire();
        break;
    case 5 :
        break;
    default:
        screen();
        break;
    }
}

int main(){
    screen();
   return 0;
}