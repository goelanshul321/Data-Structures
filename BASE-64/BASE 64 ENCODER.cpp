#include<stdio.h>
#include<string.h>
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
    int n, c ;
    printf("ENTER THE STRING TO BE ENCODED\n");
    scanf("%s", word);
    int len = strlen(word);
    for(int i = 0 ; i < strlen(word) ; i += 3 )
	{
		if( len % 3 == 0 || len / 3 > 0 && len > 0 )
		{
	    n = word[i] << 16 ;
		c =  word[i+1] << 8 ;
		n = n + c ;
		n = n + word[i+2] ;
		printf("%c ", arr[n >> 18] );
		printf("%c ", arr[n >> 12 & 63] );
		printf("%c ", arr[n >> 6 & 63] );
		printf("%c ", arr[n & 63] );
		len = len - 3;
		}
		else
		{
			if( len % 2 == 0 )
			{
				 n = word[i] << 8 ;
			     n = n + word[i+1] ;
				 n = n << 2 ;
				 printf("%c ", arr[n >> 12] );
				 printf("%c ", arr[n >> 6 & 63] );
				 printf("%c ", arr[n  & 63] );
				 printf("%c ", arr[63] );
				 len = len - 3;			
			}
			else
			{
			     n = word[i] << 4 ;
				 printf("%c ", arr[n >> 6] );
				 printf("%c ", arr[n  & 63] );
				 printf("%c ", arr[63] );
				 printf("%c ", arr[63] );
				 len = len - 3;
			}
		}
	}
}
