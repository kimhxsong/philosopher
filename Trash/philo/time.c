#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>

#include <limits.h>
void * ThreadFunc1( void * pclsArg )
{
    sleep(5);
    printf("1\n");
    return NULL;
}
void * ThreadFunc2( void * pclsArg )
{
    while(1)
    {
        sleep(2);
        printf("ok\n");
    }
    return NULL;
}

int	main( int argc, char * argv[] )
{
	int iCount = 0;
	pthread_t iThread;

    pthread_create( &iThread, NULL, ThreadFunc2, NULL );
	while( iCount <= 0)
	{
		if( pthread_create( &iThread, NULL, ThreadFunc1, NULL ) != 0 )
		{
			printf( "error = %d\n", errno );
			break;
		}
		++iCount;   
	}
    //pthread_detach(iThread);
	system("leaks a.out");
    sleep(10);
	system("leaks a.out");
	return 0;
}