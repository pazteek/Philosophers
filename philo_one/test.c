#include "philosophers.h"


static void *sss(void *arg)
{
    printf("AAaaaaa, %p\n", NULL);
     printf("AAaaaaa\n");
    return (arg);
}

int main()
{
    int i;
    long long   t1;
    long long   t2;
    pthread_t	displays;

    t1 = ft_time();
    pthread_create(&displays,  NULL ,sss , NULL);
    //sss(NULL);
    t2 = ft_time();
    printf("%lld \n", t1 - t2);
    return (0);
}