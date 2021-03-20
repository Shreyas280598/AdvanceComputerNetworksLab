#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long int i,e,d,n,p,q,phi,cipher[50];
int encrypt(char ch);
char decrypt(long int ch);
int gcd(long int a,long int b);
int main()
{
int i,len;
char text[50];
printf("enter two large prime no's");
scanf("%ld %ld",&p,&q);
printf("\n enter the text to be encrypted");
scanf("%s",text);
len=strlen(text);
n=p*q;
phi=(p-1)*(q-1);
do
{
e=rand()%phi;
}
while(gcd(e,phi)!=1);
do
{
d=rand()%phi;
}while(((d*e)%phi)!=1);
printf("\n\n two prime numbers (p&q) are :%ld %ld",p,q);
printf("\n public key(n,e):(%ld,%ld)",n,e);
printf("\n private key(phi,d):(%ld,%ld)",phi,d);
for(i=0;i<len;i++)
cipher[i]=encrypt(text[i]);
printf("\n\n encrypted message:");
for(i=0;i<len;i++)
printf("%ld",cipher[i]);
for(i=0;i<len;i++)
text[i]=decrypt(cipher[i]);
text[i]='\0';
printf("\n\n decrypted message %s \n\n",text);
return 0;
}
int gcd(long int a,long int b)
{
        if(a==0)return b;
        if(b==0)return a;
        return gcd(b,a%b);
}
int encrypt(char ch)
{
        long int temp=ch;
        for(i=1;i<e;i++)
        temp=(temp*ch)%n;
        return temp;
}
char decrypt(long int ch)
{
        long int temp=ch;
for(i=1;i<d;i++)
ch=(temp*ch)%n;
return ch;
}
