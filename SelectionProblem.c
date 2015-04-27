//[Selection Problem]
//有N个数，求出其中第k大的数字
//显示程序对于不同N的运行时间 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define  StartNum  10
#define  EndNum    100000

void swap(int *pstA, int *pstB)
{
        int temp;
        temp = *pstA;
        *pstA = *pstB;
        *pstB = temp;
        return;
}
int SortArray(int b[],const int num)
{
        int i,j;
        for(i=0; i<num; i++)
        {
                for(j=i+1; j<num; j++)
                {
                        if (b[i] < b[j])
                                swap(&b[i],&b[j]);
                }
        }
}
int Find(const int N, const int k)
{
        int a[N];
        int ulIndex = 0;

        /*输入数字*/
        while(ulIndex < N)
        {
                a[ulIndex] = rand()%10000;
                ulIndex++;
        }
        
        //排序
        SortArray(a,N);
        return a[k-1];
}
int main(int argc, char const *argv[])
{
        int     ElementNum = StartNum;
        time_t  time_begin;
        time_t  time_end;
        int     ulResult;
        double  seconds = 0;

        while(ElementNum <= EndNum)
        {
                time_begin = time(NULL);
                ulResult = Find(ElementNum, ElementNum/2);
                time_end = time(NULL);
                seconds = difftime(time_end,time_begin); 
                printf("[%d]: %lf\n", ElementNum,seconds);
                ElementNum*=10;
        }
        printf("\n");
        return 0;
}
