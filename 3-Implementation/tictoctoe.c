#include <stdio.h>
#include<time.h>
#include<stdlib.h>
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board()
{
    printf("   |   |   \n");
    printf(" %c | %c | %c\n",board[0],board[1],board[2]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c\n",board[3],board[4],board[5]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c\n",board[6],board[7],board[8]);
    printf("   |   |   \n");
}
int countb(char a)
{
    int sum=0;
    for(int i=0;i<9;i++)
    {
        if(board[i]==a)
            sum=sum+1;
    }
    return sum;
}
void computerchoice()
{
    srand(time(0));
    int ch;
    do{
        ch=rand()%10;
    }while(board[ch]!=' ');
    board[ch]='O';
}
void playerchoice()
{
    while(1)
    {
        int ch;
        printf("Enter position \n");
        scanf("%d",&ch);
        ch--;
        if(ch<0 || ch>8)
        {
            printf("Invalid position \n");
        }
        else if(board[ch]!=' ')
        {
            printf("Enter unoccupied position \n");
        }
        else{
            board[ch]='X';
            break;
        }
    }
}
void player2choice()
{
    while(1)
    {
        int ch;
        printf("Enter position \n");
        scanf("%d",&ch);
        ch--;
        if(ch<0 || ch>8)
        {
            printf("Invalid position \n");
        }
        else if(board[ch]!=' ')
        {
            printf("Enter unoccupied position \n");
        }
        else{
            board[ch]='O';
            break;
        }
    }
}
char winner()
{
    //checking winner horizontally
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ')
    {
        return board[3];
    }
    if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ')
    {
        return board[6];
    }
    //checking vertically
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
    {
        return board[1];
    }
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
    {
        return board[2];
    }
    //checking diagonally
     if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ')
    {
        return board[0];
    }
    if(board[2]==board[4] && board[4]==board[6] && board[1]!=' ')
    {
        return board[2];
    }
    if(countb('X')+countb('O')<9)
    {
        return 'C';
    }
    else{
        return 'D';
    }
}
void multiplayer(){
    char p1[20],p2[20];
    printf("Enter player1 name:");
    scanf("%s",p1);
    printf("Enter player2 name:");
    scanf("%s",p2);
    while(1){
        system("cls");
        show_board();
        if(countb('X')==countb('O'))
        {
            playerchoice();
        }
        else
        {
            player2choice();
        }
        char win=winner();
        if(win=='X')
        {
            system("cls");
            show_board();
            printf("%s won\n",p1);
            break;
        }
        else if(win=='O')
        {
            system("cls");
            show_board();
            printf("%s won\n",p2);
            break;
        }
        else if(win=='D')
        {
            system("cls");
            show_board();
            printf("match drawn\n");
            break;
        }
    }
}
       
void compvsplayer()
{
    char name[20];
    printf("Enter player name ");
    scanf("%s",name);
    while(1)
    {
        system("cls");
        show_board();
        if(countb('X')==countb('O'))
        {
            playerchoice();
        }
        else
        {
            computerchoice();
        }
        char win=winner();
        if(win=='X')
        {
            system("cls");
            show_board();
            printf("%s won\n",name);
            break;
        }
        else if(win=='O')
        {
            system("cls");
            show_board();
            printf("Computer won\n");
            break;
        }
        else if(win=='D')
        {
            system("cls");
            show_board();
            printf("match drawn\n");
            break;
        }
    }
}

int main()
{
    int ch=1;
    while(ch){
        system("cls");
        printf("1.Player vs Player\n");
        printf("2.Player vs computer\n");
        printf("3.Exit\n");
        int op;
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                multiplayer();
                break;
            case 2:
                compvsplayer();
                break;
            case 3:
                ch=0;
                break;
            default:
                printf("Enter valid option\n");
        }
    }
    return 0;
}