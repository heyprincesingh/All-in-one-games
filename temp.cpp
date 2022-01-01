/*#include<iostream>
using namespace std;

int main(){
    char a=0;
    for(int i=0;i<=256;i++){
        cout<<i<<" "<<a<<endl;
        a++;
    }
    return 0;
}*/


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
void path_way_sequence_vertical(int x,int y){
    char a=179;
    for(int i=1;i<12;i++){
        jump(x,i);
        if(i == y) cout<<" ";
    }
}
void path_way_sequence_horizontal(int x,int y){
    char a = 195,b = 196,c = 180;
    jump(x-1,y);
    cout<<a;
    jump(x,y);
    cout<<b;
    jump(x+1,y);
    cout<<c;
}
void path_way(){
    char a=179,d=193,e=194;
    for(int i=1;i<12;i++){
        jump(23,i);
        if(i == 5) cout<<d;
        else if(i == 6) cout<<" ";
        else if(i == 7) cout<<e;
        else cout<<a;
    }
    for(int j=1;j<12;j++){
        jump(24,j);
        for(int i=1;i<36;i++){
            cout<<" "<<a;
        }
    }
    
    path_way_sequence_vertical(25,10);
    path_way_sequence_vertical(27,8);
    path_way_sequence_vertical(27,4);
    path_way_sequence_vertical(27,2);
    path_way_sequence_vertical(29,2);
    path_way_sequence_vertical(31,5);
    path_way_sequence_vertical(33,11);
    path_way_sequence_vertical(35,9);
    path_way_sequence_vertical(35,3);
    path_way_sequence_vertical(35,1);
    path_way_sequence_vertical(37,2);
    path_way_sequence_vertical(39,4);
    path_way_sequence_vertical(41,6);
    path_way_sequence_vertical(43,3);
    path_way_sequence_vertical(43,9);
    path_way_sequence_vertical(43,11);
    path_way_sequence_vertical(45,10);
    path_way_sequence_vertical(47,7);
    path_way_sequence_vertical(49,3);
    path_way_sequence_vertical(51,10);
    path_way_sequence_vertical(53,8);
    path_way_sequence_vertical(55,4);
    path_way_sequence_vertical(57,2);
    path_way_sequence_vertical(57,7);
    path_way_sequence_vertical(57,10);
    path_way_sequence_vertical(59,11);
    path_way_sequence_vertical(61,8);
    path_way_sequence_vertical(63,6);
    path_way_sequence_vertical(65,10);
    path_way_sequence_vertical(67,9);
    path_way_sequence_vertical(67,4);
    path_way_sequence_vertical(65,3);
    path_way_sequence_vertical(65,1);
    path_way_sequence_vertical(67,2);
    path_way_sequence_vertical(69,2);
    path_way_sequence_vertical(71,4);
    path_way_sequence_vertical(73,3);
    path_way_sequence_vertical(75,7);
    path_way_sequence_vertical(77,10);
    path_way_sequence_vertical(77,4);
    path_way_sequence_vertical(77,2);
    path_way_sequence_vertical(79,2);
    path_way_sequence_vertical(81,6);
    path_way_sequence_vertical(83,9);
    path_way_sequence_vertical(85,11);
    path_way_sequence_vertical(87,1);
    path_way_sequence_vertical(89,5);
    path_way_sequence_vertical(91,9);
    path_way_sequence_vertical(93,2);


   // path_way_sequence_horizontal(24,9);
   // path_way_sequence_horizontal(26,6);
   // path_way_sequence_horizontal();
   // path_way_sequence_horizontal();
}
void guess_words(){
    int x=21,y=6;
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
    while(a != 'z')
    {
        path_way();
        jump(x,y);
        cout<<b;
        jump(0,13);
        a = getch();
        if(a == 'a' && x>21){
            x--;
        }
        else if(a == 's' && y<11){
            y++;
        }
        else if(a == 'w' && y>1){
            y--;
        }
        else if(a == 'd' && x<95){
            x++;
        }
    }
    jump(0,13);
    
}
int main(){
    guess_words();
    return 0;
}