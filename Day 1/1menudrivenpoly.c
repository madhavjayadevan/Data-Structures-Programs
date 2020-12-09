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
        printf("\nterm %d",i+1);
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
    int i=0,j=0,k=0;
    while(i<la && j<lb)
    {
        if(a1[i].exp==b1[j].exp)
        {
            c[k].coeff=a1[i].coeff+b1[j].coeff;
            c[k].exp=a1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(a1[i].exp>b1[j].exp)
        {
            c[k].coeff=a1[i].coeff;
            c[k].exp=a1[i].exp;
            i++;
            k++;
        }
        else if(a1[i].exp<b1[j].exp)
        {
            c[k].coeff=b1[j].coeff;
            c[k].exp=b1[j].exp;
            j++;
            k++;
        }
        
    }
    while(i<la)
	{
		c[k].coeff=a[i].coeff;
		c[k].exp=a[i].exp;
		i++;
		k++;
	}
    while (j<lb)
    {
        c[k].coeff=b1[i].coeff;
        c[k].exp=b1[i].exp;
        j++;
        k++;
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
            d[k].coeff+=(a1[i].coeff*b1[j].coeff);
            flag=1;
            }
        }
        if(flag==0)
        {
            d[q].coeff=a1[i].coeff*b1[j].coeff;
            d[q].exp=a1[i].exp+b1[j].exp;
            q++;
        }
    }

    return q+1;
}
void main()
{
    int response;
    int lc,ld,la,lb,i;
    char repeat='y';
    while(repeat=='y')
    {
        printf("<<<First Polynomial>>>");
        la=read(a);
        printf("\nThe Entered Polynomial is:");
        show(a,la);
        printf("\n\n<<<Second Polynomial>>>");
        lb=read(b);
        printf("\nThe Entered Polynomial is:");
        show(b,lb);
        printf("\n\n\n*****SELECT THE OPERATION*****\n1. Polynomial addition\n2.Polynomial Multiplication\n");
        scanf("%d",&response);
        if(response==1)
        {
            lc=addition(a,la,b,lb);
            printf("\nThe Sum is:\n");
            show(c,lc);
        }
        else if(response==2)
        {
            ld=multiplication(a,la,b,lb);
            printf("\nThe product is:\n");
            show(d,ld);
        }
        else 
        {
            printf("Wrong Input");
        }
        printf("\n\nDo you Want to Continue?(y/n)");
        scanf("%s",&repeat);
        
    }   

}