#include<stdio.h>

struct poly{
    int coeff;
    int exp;

}a[10],b[10],c[10],d[10];

int read(struct poly r[10])
{
    int l,i;
    printf("\nEnter the total number of terms:");
    scanf("%d",&l);
    for(i=0;i<l;i++){
        printf("term %d",i+1);
        printf("\nCoefficent:");
        scanf("%d",&r[i].coeff);
        printf("Exponent:");
        scanf("%d",&r[i].exp);
    }
    return l;
}

int show(struct poly r[10],int len)
{
    int i;
    printf("\n");
    for(i=0;i<len;i++)
    printf("%dX^%d+",r[i].coeff,r[i].exp);
    printf("0");
}
int addition(struct poly a1[10],int la,struct poly b1[10],int lb)
{
    int i,j,k=0,flag;
    for(i=0;i<la;i++){
        flag=0;
        for(j=0;j<lb;j++)
            if(a1[i].exp==b1[i].exp)
            {
                c[k].exp=a[i].exp;
                c[k].coeff=a1[i].coeff+b1[i].coeff;
                k++;
                flag=1;
                break;
            }
        if(flag==0){
            c[k].exp=a1[i].exp;
            c[k].coeff=a1[i].coeff;
            k++;
        }
    }
    for(i=0;i<lb;i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(c[j].exp==b1[i].exp)
            flag=1;
        }
        if(flag=0)
        {
            c[k].coeff==b1[i].coeff;
            c[k].exp=b1[i].exp;
            k++;
        }
    }
    return k;
}

int multiplication(struct poly a1[10],int la,struct poly b1[10],int lb)
{
    
    int q=0,i,j,k,flag;
    for(i=0;i<la;i++)
    for(j=0;j<lb;j++)
    {
        flag=0;
        for(k=0;k<=q;k++)
        {
            if((a1[i].exp+b1[j].exp)==d[k].exp)
            {
            d[k].coeff+=(a1[i].coeff*b1[i].coeff);
            flag=1;
            }    
        }
        if(flag=0)
        {
            d[q].coeff=a1[i].coeff*b1[j].coeff;
            d[q].exp=a1[i].exp+b1[j].exp;
            q++;
        }
    }

    return q;
}
void main()
{
    int lc,la,lb,i;
    printf("First Polynomial");
    la=read(a);
    printf("\nThe Entered Polynomial is:");
    show(a,la);
    printf("Second Polynomial");
    lb=read(b);
    printf("\nThe Entered Polynomial is:");
    show(b,lb);
    lc=multiplication(a,la,b,lb);
    printf("\nProduct is:");
    show(d,lc);
}
