#include<stdio.h>
#include<curses.h>
#include<time.h>
#include<stdlib.h>
char arr[10]={'1','2','3','4','5','6','7','8','9'};
void board()
{
    printf("\n\n\n");
    printf("     |    |    \n");
    printf("  %c  | %c  | %c \n",arr[0],arr[1],arr[2]);
    printf("_____|____|____\n");
    printf("     |    |    \n");
    printf("  %c  | %c  | %c \n",arr[3],arr[4],arr[5]);
    printf("_____|____|____\n");
    printf("     |    |    \n");
    printf("  %c  | %c  | %c \n",arr[6],arr[7],arr[8]);
    printf("     |    |    \n");
    
}
int check()
{
    if(arr[0]==arr[1] && arr[1]==arr[2])
        return 1;
    else if(arr[3]==arr[4] && arr[4]==arr[5])
        return 1;
    else if(arr[6]==arr[7] && arr[7]==arr[8])
        return 1;
    else if(arr[0]==arr[4] && arr[4]==arr[8])
        return 1;
    else if(arr[2]==arr[4] && arr[4]==arr[6])
        return 1;
    else if(arr[0]==arr[3] && arr[3]==arr[6])
        return 1;
    else if(arr[1]==arr[4] && arr[4]==arr[7])
        return 1;
    else if(arr[2]==arr[5] && arr[5]==arr[8])
        return 1;
    else if(arr[0]!='1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' && arr[6]!='7' && arr[7]!='8' && arr[8]!='9')
        return 0;
    else
        return -1;
}
void main()
{
    int player,choice,cnt;
    char mark;
    player=1;
    do
    {
        
        mark = (player==1)?'X':'o';
        board();
        if(player==1)
        {
            printf("Enter the choice Player %d:",player);
            scanf("%d",&choice);
        }
        else
        {
            srand(time(0));
            choice=(rand()%9)+1;
        }
        if(choice==1 && arr[0]=='1')
            arr[0]=mark;
        else if(choice==2 && arr[1]=='2')
            arr[1]=mark;
        else if(choice==3 && arr[2]=='3')
            arr[2]=mark;
        else if(choice==4 && arr[3]=='4')
            arr[3]=mark;
        else if(choice==5 && arr[4]=='5')
            arr[4]=mark;
        else if(choice==6 && arr[5]=='6')
            arr[5]=mark;
        else if(choice==7 && arr[6]=='7')
            arr[6]=mark;
        else if(choice==8 && arr[7]=='8')
            arr[7]=mark;
        else if(choice==9 && arr[8]=='9')
            arr[8]=mark;
        else
        {
            
            if(player ==1)
            {
                printf("Invalid Input\n");
                player=1;
            }
            else
                player=2;
            continue;
        }
        cnt=check();
        if(cnt==-1)
            if(player ==1)
                player=2;
            else
                player=1;
    }while(check()==-1);
    board();
    if(cnt==0)
        printf("GAME DRAW");
    if(cnt==1)
        printf("PLAYER %d WON THE GAME",player);
    
    
    
    
}
