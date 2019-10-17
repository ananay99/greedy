#include<stdio.h>
#include<stdlib.h>
struct job{
int id;
int deadline;
int profit;
};
int cmp(const void *a1,const void *a2)
{
 if((*(struct job *)a1).profit>(*(struct job *)a2).profit)
 {
     return 0;
 }
    return 1;
}
void job_sequence()
{
    printf("Enter number of jobs\n");
    int n;
    scanf("%d",&n);

    struct job * retarr=(struct job*)malloc(sizeof(struct job)*n);

    int mx=0;
    printf("Enter jobId-Deadline-Profit\n");
    for(int x=0;x<n;x++)
    {
        scanf("%d%d%d",&retarr[x].id,&retarr[x].deadline,&retarr[x].profit);
        if(retarr[x].deadline>mx)
            mx=retarr[x].deadline;
    }
    mx--;
    int * sequence=(int*)calloc(mx,sizeof(int));
    qsort((void*)retarr,n,sizeof(struct job),cmp);

    for(int x=0;x<n;x++)
    {
        for(int y=retarr[x].deadline-1;y>=0;y--)
        {
            if(sequence[y]==0)
            {
                sequence[y]=retarr[x].id;
                break;
            }
        }
    }
    for(int x=0;x<mx;x++)
    {
        if(sequence[x]!=0)
        {
            printf("%d ",sequence[x]);
        }
    }
    printf("\n");
}
int main()
{
    job_sequence();
    return 0;
}
