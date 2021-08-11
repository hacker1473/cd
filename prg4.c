#include<stdio.h>
void main()
 {
  char p[20][10];
  char item[20];
  int i,k,j,m,n,l,length=0,states=-1;
  char prev,current;
  //clrscr();
  printf("\n Implementation of LR Predictive Parsing Technique");
  printf("\n Enter number of productions of CFG:\n");
  scanf("%d",&n);
  printf("\n Enter %d productions:\n",n);
  for(m=1;m<=n;m++)
  {
  scanf("%s",p[m]);
  l=strlen(p[m]);
  if(l>length)
  length=l;
  }
  for(k=3;k<=length;k++)
   {

  prev= ' ';
  for(m=1;m<=n;m++)
  {
     current=p[m][k-1];
     l=strlen(p[m]);
     if(k<=l)
   {
     for(j=0,i=0;i<l;i++)
    {
    if(i==k)
    item[j++]='.';

    item[j++]=p[m][i];
     }
      if(k==l)
     item[j++]='.';

     item[j]='\0';

      if(current != prev )
      printf("\n    S%d: ",++states);

      printf("\n     %s",item);
     prev=current;
    }
  }
   }
  //getch();
}
