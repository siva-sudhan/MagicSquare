#include<stdio.h>
#define N 5
int CheckPos(int Number);
main(){
    int row ,coloumn,count,Board[N][N];//defining variables
    //initialising board to zero
    for(row = 0;row < N;row++){
        for(coloumn = 0;coloumn < N;coloumn++){
            Board[row][coloumn]=0;
        }
    }
    //setting starting position
    row = 0;
    coloumn = N/2;
    count=1;
    //feeding the magicSquare board

    while(count <= N*N){
        //printf("row=%d coloumn=%d count=%d\n",row,coloumn,count);
        if(Board[row][coloumn]== 0){
            Board[row][coloumn]=count;
            row = CheckPos(row-1);
            coloumn = CheckPos(coloumn+1);
        }
        else{
            row = CheckPos(row+2);
            coloumn = CheckPos(coloumn-1);
            Board[row][coloumn]=count;
            row = CheckPos(row-1);
            coloumn = CheckPos(coloumn+1);
        }

        count++;

    }

    //print the board
    for(row = 0;row < N;row++){
        for(coloumn = 0;coloumn < N;coloumn++){
            printf("%d ",Board[row][coloumn]);
        }
        printf("\n");
    }

//to keep the moving block within the boundary
}
int CheckPos(int Number){
        if(Number > N-1)
            Number = Number - N;
        else if(Number < 0)
            Number = Number + N;
        return Number;
}
