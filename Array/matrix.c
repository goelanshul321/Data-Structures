#include<stdio.h>
void matrix( int arr[][20], int row, int col)
{
    int i, j, x, y;
    for( i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < col ; j++)
        {
            if( !arr[i][j] )
            {
                for(x = 0 ; x < row ; x++ )
                {
                    arr[x][j] = 3 ;
                }
                
                for( y = 0 ; y < col ; y++)
                {
                    arr[i][y] = 3 ;
                }
           }
        }
    }
}
int main()
{
    int arr[20][20], row, col, i, j, mat[20][20] ;
    scanf("%d", &row) ;
    scanf("%d", &col) ;
    printf("Enter the matrix") ;
    for(i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < col ; j++)
        {
            scanf("%d", &arr[i][j]) ;
        }
    }
    matrix(arr, row, col) ; 
    for(i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < col ; j++)
        {
            if( arr[i][j] == 3 )
            { 
                arr[i][j] = 0 ;
            } 
            printf("%d ", arr[i][j]);
        }
       printf("\n ") ;
    }
    return 0;
}
