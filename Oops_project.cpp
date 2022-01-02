#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<fstream>
#include<windows.h>
#include<time.h>

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
void Game_option(){
    cout<<"\t\t\t\t\t  1. Play New Game\n\n";
    cout<<"\t\t\t\t\t  2. Exit";
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
    Game_option();
    jump(39,10);
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
char board[3][3];
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
    Game_option();
    jump(39,10);
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
    cout<<"Q U E S T I O N  ";
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
        jump(30,5);
        cout<<"Your answer was incorrect! You total won $"<<prize;
        jump(45,7);
        cout<<"Press Enter...";
        getch();
        Millionaire_restart();
    }
}
void Millionaire_congo(int prize){
    box();
    jump(43,4);
    cout<<"!!Congratulations!!";
    jump(33,6);
    cout<<"You did it! You have won total of $"<<prize;
    jump(45,8);
    cout<<"Press Enter...";
    getch();
    Millionaire_restart();
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
        
        jump(60,1);
        cout<<i;
        jump(5,4);
        cout<<data;
        jump(6,7);
        cout<<opt1;
        jump(56,7);
        cout<<opt2;
        jump(6,9);
        cout<<opt3;
        jump(56,9);
        cout<<opt4;
        jump(40,11);
        input();
        i++;
        int time = 30;
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
    Millionaire_congo(prize);
    question.close();
}

void Millionaire(){
    int m;
    box();
    jump(35,3);
    cout<<"----( Millionaire Quizard )----\n\n";
    Game_option();
    jump(39,10);
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
//Millionaire Ends

//Treasure_Hunt Finder Starts
void Treasure_Hunt_Start();
void Treasure_Hunt();
void Treasure_Hunt_box(){
    char a,b = 229,c = 186,d = 205;
    box();
    for(int i=1;i<12;i++){
        jump(20,i);
        cout<<c;
    }
    for(int i=1;i<12;i++){
        jump(96,i);
        cout<<c;
    }
    jump(1,2);
    cout<<"---< w = Up    >---";
    jump(1,3);
    cout<<"---< s = Down  >---";
    jump(1,4);
    cout<<"---< a = Left  >---";
    jump(1,5);
    cout<<"---< d = Right >---";
    jump(1,7);
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    jump(1,8);
    cout<<"      T I M E      ";
    jump(1,10);
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    jump(1,11);
    cout<<"  PRESS 0 TO EXIT  ";    
}
void Treasure_Hunt_sequence_vertical(int x,int y){
    char a=179;
    for(int i=1;i<12;i++){
        jump(x,i);
        if(i == y) cout<<" ";
    }
}
void Treasure_Hunt_sequence_horizontal(int x,int y){
    char a = 195,b = 196,c = 180;
    jump(x-1,y);
    cout<<a;
    jump(x,y);
    cout<<b;
    jump(x+1,y);
    cout<<c;
}
void Treasure_Hunt_circuit(){
    char c=179,d=193,e=194;
    for(int i=1;i<12;i++){
        jump(23,i);
        if(i == 5) cout<<d;
        else if(i == 6) cout<<" ";
        else if(i == 7) cout<<e;
        else cout<<c;
    }
    for(int j=1;j<12;j++){
        jump(24,j);
        for(int i=1;i<36;i++){
            cout<<" "<<c;
        }
    }
    for(int i=1;i<12;i++){
        jump(93,i);
        if(i == 1) cout<<d;
        else if(i == 2) cout<<" ";
        else if(i == 3) cout<<e;
        else cout<<c;
    }

    Treasure_Hunt_sequence_vertical(25,10);
    Treasure_Hunt_sequence_vertical(27,8);
    Treasure_Hunt_sequence_vertical(27,4);
    Treasure_Hunt_sequence_vertical(27,2);
    Treasure_Hunt_sequence_vertical(29,2);
    Treasure_Hunt_sequence_vertical(31,5);
    Treasure_Hunt_sequence_vertical(33,11);
    Treasure_Hunt_sequence_vertical(35,9);
    Treasure_Hunt_sequence_vertical(35,5);
    Treasure_Hunt_sequence_vertical(35,1);
    Treasure_Hunt_sequence_vertical(37,2);
    Treasure_Hunt_sequence_vertical(39,4);
    Treasure_Hunt_sequence_vertical(41,6);
    Treasure_Hunt_sequence_vertical(43,3);
    Treasure_Hunt_sequence_vertical(43,8);
    Treasure_Hunt_sequence_vertical(43,11);
    Treasure_Hunt_sequence_vertical(45,11);
    Treasure_Hunt_sequence_vertical(47,7);
    Treasure_Hunt_sequence_vertical(49,3);
    Treasure_Hunt_sequence_vertical(51,10);
    Treasure_Hunt_sequence_vertical(53,8);
    Treasure_Hunt_sequence_vertical(55,4);
    Treasure_Hunt_sequence_vertical(57,2);
    Treasure_Hunt_sequence_vertical(57,7);
    Treasure_Hunt_sequence_vertical(57,10);
    Treasure_Hunt_sequence_vertical(59,11);
    Treasure_Hunt_sequence_vertical(61,8);
    Treasure_Hunt_sequence_vertical(63,6);
    Treasure_Hunt_sequence_vertical(65,3);
    Treasure_Hunt_sequence_vertical(67,9);
    Treasure_Hunt_sequence_vertical(69,2);
    Treasure_Hunt_sequence_vertical(71,4);
    Treasure_Hunt_sequence_vertical(73,3);
    Treasure_Hunt_sequence_vertical(75,7);
    Treasure_Hunt_sequence_vertical(77,10);
    Treasure_Hunt_sequence_vertical(77,4);
    Treasure_Hunt_sequence_vertical(77,2);
    Treasure_Hunt_sequence_vertical(79,2);
    Treasure_Hunt_sequence_vertical(81,6);
    Treasure_Hunt_sequence_vertical(83,9);
    Treasure_Hunt_sequence_vertical(85,11);
    Treasure_Hunt_sequence_vertical(87,1);
    Treasure_Hunt_sequence_vertical(89,5);
    Treasure_Hunt_sequence_vertical(91,9);
    
    Treasure_Hunt_sequence_vertical(29,10);
    Treasure_Hunt_sequence_vertical(37,11);
    Treasure_Hunt_sequence_vertical(39,9);
    Treasure_Hunt_sequence_vertical(47,2);
    Treasure_Hunt_sequence_vertical(61,2);
    Treasure_Hunt_sequence_vertical(63,10);
    Treasure_Hunt_sequence_vertical(71,7);
    Treasure_Hunt_sequence_vertical(71,11);



    Treasure_Hunt_sequence_horizontal(24,2);
    Treasure_Hunt_sequence_horizontal(26,5);
    Treasure_Hunt_sequence_horizontal(28,3);
    Treasure_Hunt_sequence_horizontal(32,3);
    Treasure_Hunt_sequence_horizontal(34,8);
    Treasure_Hunt_sequence_horizontal(36,4);
    Treasure_Hunt_sequence_horizontal(42,7);
    Treasure_Hunt_sequence_horizontal(44,10);
    Treasure_Hunt_sequence_horizontal(56,6);
    Treasure_Hunt_sequence_horizontal(58,9);
    Treasure_Hunt_sequence_horizontal(76,5);
    Treasure_Hunt_sequence_horizontal(78,3);

    Treasure_Hunt_sequence_horizontal(30,7);
    Treasure_Hunt_sequence_horizontal(38,6);
    Treasure_Hunt_sequence_horizontal(40,3);
    Treasure_Hunt_sequence_horizontal(40,8);
    Treasure_Hunt_sequence_horizontal(46,6);
    Treasure_Hunt_sequence_horizontal(52,5);
    Treasure_Hunt_sequence_horizontal(54,3);
    Treasure_Hunt_sequence_horizontal(62,5);
    Treasure_Hunt_sequence_horizontal(64,9);
    Treasure_Hunt_sequence_horizontal(70,10);
    Treasure_Hunt_sequence_horizontal(72,6);
    Treasure_Hunt_sequence_horizontal(84,8);
    Treasure_Hunt_sequence_horizontal(90,10);
}
void Treasure_Hunt_restart(){
    int opt;
    box();
    init:
    jump(38,3);
    cout<<"----( Treasure Hunt )----\n\n";
    jump(43,5);
    cout<<"1. Play again";
    jump(43,7);
    cout<<"2. Exit"; 
    jump(40,9);
    input();
    opt = getch();
    opt -= 48;
    if(opt == 1) Treasure_Hunt();
    else if(opt == 2) screen();
    else goto init;
}
time_t original_hunt_time,hunt_time;
void Treasure_Hunt_Congo(){
    box();
    int total_time = hunt_time - original_hunt_time;
    jump(44,3);
    cout<<"!!Congratulations!!";
    if(total_time<60){
        jump(33,6);
        cout<<"You did it! You took total of "<<total_time<<" Seconds";
    }
    else{
        jump(27,6);
        cout<<"You did it! You took total of "<<total_time/60<<" minutes and "<<total_time%60<<" Seconds";
    }
    jump(46,8);
    cout<<"Press Enter...";
    getch();
    Treasure_Hunt_restart();
}
void hunt_timer(){
    time(&hunt_time);
    jump(9,9);
    cout<<hunt_time - original_hunt_time;
}
void Treasure_Hunt(){
    int x=21,y=6,flagg = 0;
    time(&original_hunt_time);
    char a,b = 229;
    Treasure_Hunt_box();
    Treasure_Hunt_circuit();
    game:
    while(!kbhit() && x<=94){
        if(flagg==0){
            hunt_timer();
            jump(x,y);
            cout<<b;
            jump(x,y);
        }
        else if(flagg==1) Treasure_Hunt_Start();
    }
    a = getch();
    if(a == 48) flagg = 1;
    if(a == 'a' && x>21 && ( x < 24 || x%2!=0 ||(x == 24 && y == 6) || (x == 26 && y == 10) || (x == 28 && y == 8) || (x == 28 && y == 4) || (x == 28 && y == 2) || (x == 30 && y == 2) || (x == 32 && y == 5) || (x == 34 && y == 11) || (x == 36 && y == 9) || (x == 36 && y == 5) || (x == 36 && y == 1) || (x == 38 && y == 2) || (x == 40 && y == 4) || (x == 42 && y == 6) || (x == 44 && y == 3) || (x == 44 && y == 8) || (x == 44 && y == 11) || (x == 46 && y == 11) || (x == 48 && y == 7) || (x == 50 && y == 3) || (x == 52 && y == 10) || (x == 54 && y == 8) || (x == 56 && y == 4) || (x == 58 && y == 2) || (x == 58 && y == 7) || (x == 58 && y == 10) || (x == 60 && y == 11) || (x == 62 && y == 8) || (x == 64 && y == 6) || (x == 66 && y == 3) || (x == 68 && y == 9) || (x == 70 && y == 2) || (x == 72 && y == 4) || (x == 74 && y == 3) || (x == 76 && y == 7) || (x == 78 && y == 10) || (x == 78 && y == 4) || (x == 78 && y == 2) || (x == 80 && y == 2) || (x == 82 && y == 6) || (x == 84 && y ==9) || (x == 86 && y ==11) || (x == 88 && y ==1) || (x == 90 && y ==5) || (x == 92 && y ==9) || (x == 30 && y == 10) || (x == 38 && y == 11) || (x == 40 && y == 9) || (x == 48 && y == 2) || (x == 62 && y == 2) || (x == 64 && y == 10) || (x == 72 && y == 7) || (x == 72 && y ==11) ) ){
        cout<<" ";
        x--;
    }
    else if(a == 's' && y<11 && ( x<23 || x%2==0 && ( x==24 || x==48 || x==50 || x==60 || x==66 || x==68 || x==74 || x==80 || x==82 || x==86 || x==88 || x==92 || (x==26 && y!=4) || (x==28 && y!=2) || (x==30 && y!=6) || (x==32 && y!=2) || (x==34 && y!=7) || (x==36 && y!=3) || (x==38 && y!=5) || (x==40 && y!=7 && y!=2) || (x==42 && y!=6) || (x==44 && y!=9) || (x==46 && y!=5) || (x==52 && y!=4) || (x==54 && y!=2) || (x==56 && y!=5) || (x==58 && y!=8) || (x==62 && y!=4) || (x==64 && y!=8) || (x==70 && y!=9) || (x==72 && y!=5) || (x==76 && y!=4) || (x==78 && y!=2) || (x==84 && y!=7) || (x==90 && y!=9)  ) ) ){
        cout<<" ";
        y++;
    }
    else if(a == 'w' && y>1 && ( x<23 || x%2==0 && ( x==21 || x==22 || x==48 || x==50 || x==60 || x==66 || x==68 || x==74 || x==80 || x==82 || x==86 || x==88 || x==90 || x==92 || (x==24 && y!=3) || (x==26 && y!=6) || (x==28 && y!=4) || (x==30 && y!=8) || (x==32 && y!=4) || (x==34 && y!=9) || (x==36 && y!=5) || (x==38 && y!=7) || (x==40 && y!=9 && y!=4) || (x==42 && y!=8) || (x==44 && y!=11) || (x==46 && y!=7) || (x==52 && y!=6) || (x==54 && y!=4) || (x==56 && y!=7) || (x==58 && y!=10) || (x==62 && y!=6) || (x==64 && y!=10) || (x==70 && y!=11) || (x==72 && y!=7) || (x==76 && y!=6) || (x==78 && y!=4) || (x==84 && y!=9) ) ) ){
        cout<<" ";
        y--;
    }
    else if(a == 'd' && x<95 && (x%2!=0 ||(x == 22 && y == 6) || (x == 24 && y == 10) || (x == 26 && y == 8) || (x == 26 && y == 4) || (x == 26 && y == 2) || (x == 28 && y == 2) || (x == 30 && y == 5) || (x == 32 && y == 11) || (x == 34 && y == 9) || (x == 34 && y == 5) || (x == 34 && y == 1) || (x == 36 && y == 2) || (x == 38 && y == 4) || (x == 40 && y == 6) || (x == 42 && y == 3) || (x == 42 && y == 8) || (x == 42 && y == 11) || (x == 44 && y == 11) || (x == 46 && y == 7) || (x == 48 && y == 3) || (x == 50 && y == 10) || (x == 52 && y == 8) || (x == 54 && y == 4) || (x == 56 && y == 2) || (x == 56 && y == 7) || (x == 56 && y == 10) || (x == 58 && y == 11) || (x == 60 && y == 8) || (x == 62 && y == 6) || (x == 64 && y == 3) || (x == 66 && y == 9) || (x == 68 && y == 2) || (x == 70 && y == 4) || (x == 72 && y == 3) || (x == 74 && y == 7) || (x == 76 && y == 10) || (x == 76 && y == 4) || (x == 76 && y == 2) || (x == 78 && y == 2) || (x == 80 && y == 6) || (x == 82 && y ==9) || (x == 84 && y ==11) || (x == 86 && y ==1) || (x == 88 && y ==5) || (x == 90 && y ==9) || (x == 92 && y == 2) || (x == 28 && y == 10) || (x == 36 && y == 11) || (x == 38 && y == 9) || (x == 46 && y == 2) || (x == 60 && y == 2) || (x == 62 && y == 10) || (x == 70 && y == 7) || (x == 70 && y ==11) ) ){
        cout<<" ";
        x++;
    }
    if(x>=94) Treasure_Hunt_Congo();
    goto game;
}
void Treasure_Hunt_Start(){
    int m;
    box();
    jump(38,3);
    cout<<"----( Treasure Hunt )----\n\n";
    Game_option();
    jump(39,10);
    input();
    m = getch();
    m -= 48;
    switch (m)
    {
        case 1:
        Treasure_Hunt();
        break;
        
        case 2:
        screen();
        break;
        
        default:
        Treasure_Hunt_Start();
        break;
    }
}
//Treasure_Hunt Finder Ends

void screen(){
    int a;
    box();
    jump(33,3);
    cout<<"Welcome to All-in-One Gaming Console\n\n";
    cout<<"\t\t\t\t     1. Lottery - Guess the digit\n";
    cout<<"\t\t\t\t     2. Tic Tac Toe\n";
    cout<<"\t\t\t\t     3. Millionaire Quizard \n";
    cout<<"\t\t\t\t     4. Treasure Hunt\n";
    cout<<"\t\t\t\t     5. Exit";
    jump(38,11);
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
    case 4 :
        Treasure_Hunt_Start();
        break;
    case 5 :
        jump(0,13);
        exit(0);
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