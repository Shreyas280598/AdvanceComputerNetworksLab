#include<stdio.h>
#include<string.h>
# define n strlen(g)
char t[28],cs[28],g[]="1000100000100001";
int a,e,c;
void xor()
{
  for(c=1;c<n;c++)
  cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc()
{
 for(e=0;e<n;e++)
 cs[e]=t[e];
 do
 {
  if(cs[0]=='1')
  xor();
  for(c=0;c<n-1;c++)
  cs[c]=cs[c+1];
  cs[c]=t[e++];
 }
 while(e<=a+n-1);
}
void main()
{
 printf("\n enter the data :");
 scanf("%s",t);
 printf("\n generating polynomial : %s",g);
 a=strlen(t);
 for(e=a;e<a+n-1;e++)
 t[e]='0';
 printf("\n modified data is :%s",t);
 crc();
 printf("\n checksum is :%s",cs);
 for(e=a;e<a+n-1;e++)
 t[e]=cs[e-a];
 printf("\n final codeword is:%s",t);
 printf("\n test error detection 0(yes) 1(no)?:");
 scanf("%d",&e);
 if(e==0)
 { 
do
   {
     printf("\n enter the position where error is to be inserted :");
     scanf("%d",&e);
   }
   while(e==0||e>a+n-1);
   t[e-1]=(t[e-1]=='0')?'1':'0';
   printf("\n erroneous data:%s\n",t);
 }
 crc();
 for(e=0;(e<n-1) && (cs[e]!='1');e++);
 if(e<n-1)
 printf("\n error detected \n\n");
 else
 printf("\n no errors detected\n\n");
}
