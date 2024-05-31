#include<stdio.h>
#include<string.h>

char arr[]={'1','2','3','4','5','6','7','8','9'};
void printBoard();
void player(int a); 
int check();
int win();
int chance=1;

int main(){

    printf("Hello players,\nwelcome to the game \n:: THE TIC TAC TOE::\n");
    printf("So, here the game starts.\n");
    printBoard();
    if(win()==1)
    printf("player 1 is winner.");
    else
    printf("player 2 is winner.");

    return 0;
}
int check(){
    if(arr[0]==arr[1]&&arr[1]==arr[2])
    return 1;
    if(arr[3]==arr[4]&&arr[4]==arr[5])
    return 1;
    if(arr[6]==arr[7]&&arr[7]==arr[8])
    return 1;
    if(arr[0]==arr[3]&&arr[3]==arr[6])
    return 1; 
    if(arr[1]==arr[4]&&arr[4]==arr[7])
    return 1;
    if(arr[2]==arr[5]&&arr[5]==arr[8])
    return 1;
    if(arr[0]==arr[4]&&arr[4]==arr[8])
    return 1; 
    if(arr[2]==arr[4]&&arr[4]==arr[6])
    return 1;
    else 
    return 0;
}
 int win(){
     while (check()==0)
     {
        chance=chance%2;
        player(chance);
        printBoard();
        chance++;
     }
     return (chance-1);
 }
void printBoard(){
    printf("\n");
    printf("  %c  ||  %c   ||  %c  \n",arr[0],arr[1],arr[2]);
    printf("=====||======||=====\n");
    printf("  %c  ||  %c   ||  %c  \n",arr[3],arr[4],arr[5]);
    printf("=====||======||=====\n");
    printf("  %c  ||  %c   ||  %c  \n",arr[6],arr[7],arr[8]);
    printf("\n");
}
void player(int a){
    int b,ch=a;
    if(a==0)
    ch=2;
    printf("player %d enter your position : ",ch);
    scanf("%d",&b);
    if(arr[b-1]=='X' || arr[b-1]=='O')
    {
        printf("this position is already used.\nplease try different position.\n");
        player(a);
    }
    else
    {
        if(b>0 && b<10)
        {
            if(a==1)
            arr[b-1]='X';
            if(a==0)
            arr[b-1]='O';
        }
        else
        {
            printf("invalid position.\n");
            player(a);
        }
    }
}
