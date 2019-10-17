#include<stdio.h>
#include<stdlib.h>
struct work{
int starttime;
int endtime;
};
int cmp(const void *a1,const void *a2)
{
 if((*(struct work *)a1).endtime<(*(struct work *)a2).endtime)
 {
     return 0;
 }
    return 1;
}
struct work * take_input(int * size)
{
    printf("Enter number of processes\n");
    int n;
    scanf("%d",&n);
    *size=n;

    struct work * retarr=(struct work*)calloc(n,sizeof(struct work));

    printf("Enter start time and end time\n");
    for(int x=0;x<n;x++)
    {
        scanf("%d%d",&retarr[x].starttime,&retarr[x].endtime);
    }
    return retarr;
}
void interval_schedule(struct work * arr,int n)
{
    int workcount=0;
    qsort((void*)arr,n,sizeof(struct work),cmp);
    if(n>0)
    {
        printf("%d\n",workcount+1);
    }
    for(int x=1;x<n;x++)
    {
        if(arr[x].starttime>=arr[workcount].endtime)
        {
            printf("%d\n",x+1);
            workcount=x;
        }
    }
    printf("total jobs done=%d\n",workcount+1);
}
int main()
{
    int size=0;
    struct work * arr=take_input(&size);
    interval_schedule(arr,size);
    return 0;
}
