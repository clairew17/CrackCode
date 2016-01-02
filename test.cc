#include"header.h"

int main()
{
    char s[5]={'s','a','\0','c','h'};
    char p[5];
    char t[5];
    strcpy(p,s);
    memcpy(t,s,5);
    printf("sachin p is [%s]\n t is [%s]\n",p,t);
    return 0;
}