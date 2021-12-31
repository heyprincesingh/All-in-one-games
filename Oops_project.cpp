#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<fstream>
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
    opt = getch();
    opt -= 48;
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
    l = getch();
    l -= 48;
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
            jump(30,11);
            cout<<"Invalid Move";
    }

    if(turn == 'x' && board[row][column] != 'x' && board[row][column] != 'o'){
        board[row][column] = 'x';
        turn = 'o';
    }else if(turn == 'o' && board[row][column] != 'x' && board[row][column] != 'o'){
        board[row][column] = 'o';
        turn = 'x';
    }else {
        jump(30,11);
        cout<<"Invalid Move! Please choose another place!!";
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
        cout<<"!!GAME DRAW!!";
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
    opt = getch();
    opt -= 48;
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
    cout<<"\t\t\t\t\t  2. Exit";
    jump(38,10);
    input();
    t = getch();
    t -= 48;
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
//TicTacToe code over


//Millionaire code starts
void Millionaire_question();
void Millionaire_question_screen(){
    box();
    char p = 219,a = 186, b = 206, c = 205,d = 203,e = 202;
    jump(42,1);
    cout<<"Q U E S T I O N  1";     //jump(60,1);
    jump(0,2);
    for(int i=0;i<100;i++){
       cout<<p;
   }
   jump(1,6);
    for(int i=0;i<98;i++){
       if(i==3 || i==49 || i==53) cout<<d;
       else cout<<c;
   }
   jump(1,8);
    for(int i=0;i<98;i++){
       cout<<c;
   }
   jump(1,10);
    for(int i=0;i<98;i++){
       if(i==3 || i==49 || i==53) cout<<e;
       else cout<<c;
   }

   jump(4,7);
   cout<<a;
   jump(4,8);
   cout<<b;
   jump(4,9);
   cout<<a;

   jump(50,7);
   cout<<a;
   jump(50,8);
   cout<<b;
   jump(50,9);
   cout<<a;

   jump(54,7);
   cout<<a;
   jump(54,8);
   cout<<b;
   jump(54,9);
   cout<<a;

   jump(2,7);
   cout<<"1";
   jump(52,7);
   cout<<"2";
   jump(2,9);
   cout<<"3";
   jump(52,9);
   cout<<"4";
}
void Millionaire_restart(){
    int opt;
    box();
    init:
    jump(35,3);
    cout<<"----( Millionaire Quizard )----\n\n";
    jump(43,5);
    cout<<"1. Play again";
    jump(43,7);
    cout<<"2. Exit"; 
    jump(36,9);
    input();
    opt = getch();
    opt -= 48;
    if(opt == 1) Millionaire_question();
    else if(opt == 2) screen();
    else goto init;
}
void Millionaire_check(bool check,int prize){
    box();
    if(check){
        int question_timer = 10;
        jump(25,5);
        cout<<"You gave the correct answer and you have won $"<<prize<<"....";
        jump(36,7);
        cout<<"Next Question in ";
        while(question_timer>0){
            jump(53,7);
            cout<<question_timer<<" seconds  ";
            question_timer--;
            Sleep(1000);
        }
    }
    else{
        jump(28,5);
        cout<<"Your answer was incorrect! You total won $"<<prize;
        jump(45,7);
        cout<<"Press Enter...";
        getch();
        Millionaire_restart();
    }
}
void Millionaire_question(){
    bool option;
    string data,opt1,opt2,opt3,opt4,ans,opt;
    int i = 1,prize = 0;
    ifstream question("question.txt");
    do{
        Millionaire_question_screen();
        getline(question,data);
        getline(question,opt1);
        getline(question,opt2);
        getline(question,opt3);
        getline(question,opt4);
        getline(question,ans);
        
        jump(5,4);
        cout<<data;
        jump(6,7);
        cout<<opt1;
        jump(56,7);
        cout<<opt2;
        jump(6,9);
        cout<<opt3;
        jump(56,9);
        cout<<opt4<<" "<<ans;
        jump(40,11);
        input();
        i++;
        int time = 10;
        while(!_kbhit() && time>=0){
            jump(95,2);
            cout<<"   ";
            jump(96,2);
            cout<<time;
            time--;
            jump(61,11);
            Sleep(1000);
        }
        if(time >= 0) opt = getch();
        if(ans==opt){
            prize += 500;
            Millionaire_check(true,prize);
            option = true;
        }
        else{
            option = false;
            question.close();
            Millionaire_check(false,prize);
        }
    }while(option && i<=13);
    question.close();
}

void Millionaire(){
    int m;
    box();
    jump(35,3);
    cout<<"----( Millionaire Quizard )----\n\n";
    cout<<"\t\t\t\t\t  1. Play New Game\n\n";
    cout<<"\t\t\t\t\t  2. Exit";
    jump(38,10);
    input();
    m = getch();
    m -= 48;
    switch (m)
    {
        case 1:
        Millionaire_question();
        break;
        
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
    a = getch();
    a -= 48;
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