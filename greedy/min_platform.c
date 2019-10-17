#include<stdio.h>
#include<stdlib.h>
struct train_time_action{
  char action;
  int time;
};
struct train_time_action * take_input(int * size)
{
    printf("Enter number of train\n");
    int n;
    scanf("%d",&n);
    n=n*2;
    *size=n;
    struct train_time_action * retarr=(struct train_time_action*)calloc(n,sizeof(struct train_time_action));

    printf("Enter arrival and departure time of train\n");
    for(int x=0;x<n;x+=2)
    {
        scanf("%d",&retarr[x].time);
        retarr[x].action='a';
        scanf("%d",&retarr[x+1].time);
        retarr[x+1].action='d';
    }

    return retarr;
}
int cmp(const void *a1,const void *a2)
{
 if((*(struct train_time_action *)a1).time<(*(struct train_time_action *)a2).time)
 {
     return 0;
 }
    return 1;
}
int platform_required(struct train_time_action * arr,int size)
{
    qsort((void*)arr,size,sizeof(struct train_time_action),cmp);
    int totalplatform=0;
    int retmx=0;
    for(int x=0;x<size;x++)
    {
        if(arr[x].action=='a')
            totalplatform++;
        else
            totalplatform--;
        if(totalplatform>retmx)
            retmx=totalplatform;
    }
    return retmx;
}
int main()
{
    int size=0;
    struct train_time_action * arr=take_input(&size);
    printf("%d\n",platform_required(arr,size));
    return 0;
}
