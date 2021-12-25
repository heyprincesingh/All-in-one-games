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
    cout<<"\n\t\t\t\tChoose your option : ";
}
void guessnumber_box(){
    box();
    jump(30,2);
    cout<<"----(Lottery - Guess the digit)----";
}
void guessnumber_indicator(int l, bool temp,int dif){
    char a = 205,b = 206,c = 31/*20*/,d = 23,e = 200,f = 188,g = 186;
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
    int num,g,count = 1;
    string name;
    srand(time(0));
    num = rand() % 100 + 1;
    guessnumber_box();
    jump(32,4);
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
    guessnumber_box();
    jump(20,7);
    cout<<"You made it "<<name<<"...It took you "<<count<<" chances to guess it right!";
    jump(0,13);   
}
void guessnumber(){
    int l;
    box();
    jump(28,3);
    cout<<"----(Lottery - Guess the digit)----\n\n";
    cout<<"\t\t\t\t  1. Play New Game\n";
    cout<<"\t\t\t\t  2. High Score\n";
    cout<<"\t\t\t\t  3. Exit";
    jump(33,10);
    input();
    cin>>l;
    switch (l)
    {
        case 1:
        guessnumber_screen();
        break;
        case 3:
        screen();
        break;
    
    default:
        break;
    }
}
void tictactoe(){
    int t;
    box();
    jump(30,3);
    cout<<"----( Tic - Tac - Toe )----\n\n";
    cout<<"\t\t\t\t  1. Play New Game\n";
    cout<<"\t\t\t\t  2. High Score\n";
    cout<<"\t\t\t\t  3. Exit\n\n\n\n";
    jump(33,10);
    input();
    cin>>t;
    switch (t)
    {
    case 3:
        screen();
        break;
    
    default:
        break;
    }
}
void Millionaire(){
    int m;
    box();
    jump(28,3);
    cout<<"----( Millionaire Quizard )----\n\n";
    cout<<"\t\t\t\t  1. Play New Game\n";
    cout<<"\t\t\t\t  2. High Score\n";
    cout<<"\t\t\t\t  3. Exit\n\n\n\n";
    jump(33,10);
    input();
    cin>>m;
    switch (m)
    {
    case 3:
        screen();
        break;
    
    default:
        break;
    }
}
void screen(){
    int a;
    box();
    jump(30,3);
    cout<<"Welcome to All-in-One Gaming Console\n\n";
    cout<<"\t\t\t\t  1. Lottery - Guess the digit\n";
    cout<<"\t\t\t\t  2. Tic Tac Toe\n";
    cout<<"\t\t\t\t  3. Millionaire Quizard \n";
    cout<<"\t\t\t\t  4. \n";
    cout<<"\t\t\t\t  5. Exit\n\n\n\n";
    jump(33,10);
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