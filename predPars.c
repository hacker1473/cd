/*A c program to implement perdictive parsing for grammar
e->tb,b->+tb,b->@,t->fc,c->*fc,c->@,f->i/(e)*/
#include <stdio.h>
#include<string.h>
char s[20],stack[20];
void main()
{
char m[5][6][3]={"tb"," "," ","tb"," "," "," ","+tb"," "," ","n","n","fc"," "," ","fc"," "," "," ","n","*fc"," ","n","n","i"," ","","(e)"," "," "};
int sizer[5][6]={2,0,0,2,0,0,0,3,0,0,1,1,2,0,0,2,0,0,0,1,3,0,1,1,1,0,0,3,0,0};
int i,j,k,n,str1,str2;
printf("\nenter string:");
scanf("%s",s);
n=strlen(s);
stack[0]='$';
stack[1]='e';
i=1;
j=0;
printf("\n stack \t\t input\n");
printf("------------------------------------\n");
while((stack[i]!='$')&&(s[j]!='$'))
{
if(stack[i]==s[j])//both elements on stack and ip are same
{
i--;
j++;
}
switch(stack[i])//in table it represents rows as non-terminals
{
case 'e':str1=0;
break;
case 'b':str1=1;
break;
case 't':str1=2;
break;
case 'c':str1=3;
break;
case 'f':str1=4;
break;
}
switch(s[j])//columns represent terminals
{
case 'i':str2=0;
break;
case '+':str2=1;
break;
case '*':str2=2;
break;
case '(':str2=3;
break;
case ')':str2=4;
break;
case '$':str2=5;
break;
}
if(m[str1][str2][0]==' ')
{
printf("\nerror");
exit(0);
}
else if(m[str1][str2][0]=='n')//IF EPCILON
{
i--;
}
else if(m[str1][str2][0]=='i')//IF INPUT MATCHES AS i
{
stack[i]='i';
}
else
{
for(k=sizer[str1][str2]-1;k>=0;k--)
{
stack[i]=m[str1][str2][k];//elements on right side of production
i++;
}
i--;
}
for(k=0;k<=i;k++)
printf("%c",stack[k]);//print elements on stack
printf("\t\t");
for(k=j;k<=n;k++)
printf("%c",s[k]);//print elements on ip string
printf("\n");
}
printf("\nsucess");
}
								

