#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
char *game[] = {"Rock","Paper","Scissor"};


int gameover()
{
    printf("\n\nIf you want to continue enter 1 otherwise enter any no : ");
    int x;
    scanf("%d",&x);

return x;
}

void display()
{
    srand(time(NULL));
    int x= rand()%3;
    int y = rand()%3;

    char p1[10],p2[10];

    strcpy(p1,game[x]);
    strcpy(p2,game[y]);

    printf("PLAYER : %s",p1);
    printf("\nCOMPUTER : %s",p2);


    if(strcmp(p1,p2)==0)
        printf("\n\t\t\tMatch Tied");

    else if( strcmp(p1,"Rock")==0 && strcmp(p2,"Paper")==0 )
        printf("\n\t\t\tOOPS , COMPUTER WINS");

    else if( strcmp(p1,"Rock")==0 && strcmp(p2,"Scissor")==0 )
        printf("\n\t\t\tCongratulations , PLAYER WINS");


    else if( strcmp(p1,"Paper")==0 && strcmp(p2,"Rock")==0 )
        printf("\n\t\t\tCongratulations , PLAYER WINS");

    else if( strcmp(p1,"Paper")==0 && strcmp(p2,"Scissor")==0 )
        printf("\n\t\t\tOOPS , COMPUTER WINS");

    else if( strcmp(p1,"Scissor")==0 && strcmp(p2,"Rock")==0 )
        printf("\n\t\t\tOOPS , COMPUTER WINS");

    else if( strcmp(p1,"Scissor")==0 && strcmp(p2,"Paper")==0 )
          printf("\n\t\t\tCongratulations , PLAYER WINS");
}

int main()
{
    start:
    system("cls");
    printf("\t\t\t\tWELCOME");
    printf("\n\t\t\t Rock Paper Scissors\n");
    display();
    int z=gameover();

    if(z==1)
        goto start;
    else
        printf("\n\t\t\t!!!!!!  Thanks For Playing  !!!!!!\n\n");

}

