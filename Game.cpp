#include <iostream>
#include <conio.h>
#include <time.h> 

using namespace std;

int row = 14;
int column = 6;
int pi=12,pj=3,c=0,oi,oj,n=500;
int score=0,life=1,fi,fj,lvl=0;
void draw();
void control();
void obstacles();
void fruit();
void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock();  
   while (clock() < start_time + milli_seconds) 
        ; 
} 
int main()
{   
    while(life)
    {  draw();    
       delay(n);
       control();           
    }
    printf("\n\n\n\t\t**gameover**");
    return 0;
}
void draw()
{      if(n%13==0) 
           {  obstacles();
              fruit();       }    
          else
             { oi++;fi++;}
              
              
       int i, j;n++;
       clrscr();
    printf(" score= %d \n life= %d lvl= %d\n",score,life,lvl);
    printf("press 4 and 6 for left and right \n");
       for(i=0; i<=row; i++)
       {    if(oi==pi && (oj==pj))
                {  life=0;}
            if(fi==pi && (fj==pj))
                {  score+=10;
                   if(score%1500==0)
                       {  n=n-50;
                         lvl++;}
                }
         for(j=0; j<=column; j++)
            if( j==0 ||  j==column)
            {  if(c%4==0)
                   printf("^");
                else if(c%3==1)
                    printf(" ");
                else if(c%3==2)
                    printf("^");
                else
                    printf(" ");
            }
            else if(i==pi && j==pj)
                    printf("😍");
            else if(i==oi && j==oj)
                  {  printf("🔥");         
                   }  
            else if(i==fi && j==fj) 
                    printf("🎁");      
            else {
                printf("  ");
             }
         printf("\n");
         c++;
       }
    
}

void control()
{ 
  if (_kbhit()) 
     { switch(_getch())
       { case '4':
          { pj--;
            break;}                         
        case '6':
          {  pj++;
            break;}
          }
   }
}
void fruit()
{
    fi = 0;
    fj = rand()%4+1;
}
void obstacles() 
{    
     oi = 0;
     oj = rand()%4+1;
}
