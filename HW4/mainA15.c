#include <stdio.h>

 int main()
{
    int X1 = 0;
    int Y1 = 0;
    int X2 = 0;
    int Y2 = 0;
    float K = 0.0;
    float B = 0.0;
    scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
    K = (((float)(Y1-Y2))/((float)(X1-X2)));
    B = (float)(Y2-K*X2);
    printf("%.2f %.2f\n",K,B);
}
