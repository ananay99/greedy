#include<stdio.h>
#include<stdlib.h>
void input(int ** ar,int n)
{
    printf("Enter value and weight\n");
    for(int x=0;x<n;x++)
    {
        scanf("%d%d",&ar[x][0],&ar[x][1]);
    }

}
int cmp(const void *a1,const void *a2)
{
    int **o=((const int*)a1);
    int **p=((const int*)a2);
    double a=((double)(o[0][0]))/o[0][1];
    double b=((double)(p[0][0]))/p[0][1];
    return(b-a);
}
void knapsack(int **arr,int n,int weight)
{
    double fvalue=0.0;
    qsort((void*)arr,n,sizeof(arr[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(weight>=arr[i][1])
        {
            weight-=arr[i][1];
            fvalue+=((double)(arr[i][0]));
        }
        else
        {
            fvalue+=(((double)(arr[i][0]))/arr[i][1])*weight;
            break;
        }
    }
    printf("%lf\n",fvalue);
}
int main()
{
    int n,weight;
    printf("Enter total items\n");
    scanf("%d",&n);
    int **ar=(int**)calloc(n,sizeof(int*));
    for(int x=0;x<n;x++)
    {
        ar[x]=(int*)calloc(2,sizeof(int));
    }
    input(ar,n);
    printf("Enter total weight that can be stored\n");
    scanf("%d",&weight);
    knapsack(ar,n,weight);
    return 0;
}
