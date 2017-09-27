#include<stdio.h>
#include<string.h>

int findIndex(char *array, int size, int target) 
{
    int i=0;
    while((i<size) && (array[i] != target)) i++;

    return (i<size) ? (i) : (-1);
}
int main()
{
	char word[20], arr[64] = {  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '='  };
     printf("ENTER THE STRING TO BE DECODED\n") ;
     scanf("%s", word) ;
     int p = 0, n ;
     	char x, y, z, w ;
     int len = strlen(word) ;
     for( int i = 0 ; i < len ; i += 4 )
     {
        	if( word[i] != '=' && word[i+1] != '=' && word[i+2] != '=' && word[i+3] != '=' )
     	    {
		        x = word[i] ;
     	        y = word[i+1] ;
     			z = word[i+2] ;
     			w = word[i+3] ;
     			int o = findIndex( arr , 64 , x );
        		int j = findIndex( arr , 64 , y );
   		        int k = findIndex( arr , 64 , z );
        		int l = findIndex( arr , 64 , w );
		        n = o << 18 ;
		        p = j << 12 ;
		        n = n + p ;
		        p = k << 6 ;
		        n = n + p ;
		        n = n + l ;
		        printf("%c " , n >> 16 );
		        printf("%c " , n >> 8 );
		        printf("%c " , n & 255 );
			}
			else
		    {
		    	if(word[i+2] == '=' )
		    	{
		    		x = word[i] ;
     	        	y = word[i+1] ;
     	        	int o = findIndex( arr , 64 , x );
        			int j = findIndex( arr , 64 , y );
     	            n = o << 6 ;
     	            n = n + j ;
     	            n = n >> 4 ;
     	            printf("%c " , n );
     	            p = 1 ;
				}
		    	if(word[i+3] == '=' && p != 1 )
		    	{
		    		x = word[i] ;
     	        	y = word[i+1] ;
     	        	z = word[i+2] ;
     	        	int o = findIndex( arr , 64 , x );
        			int j = findIndex( arr , 64 , y );
        		    int k = findIndex( arr , 64 , z );
     	            n = o << 12 ;
     	            p = j << 6 ;
     	            n = n + p ;
     	            n = n + k ;
     	            n = n >> 2 ;
     	            printf("%c " , n >> 8 ) ;
     	            printf("%c " , n & 255 ) ;
				}
			}
	 }
}
