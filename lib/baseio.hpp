#ifdef _BASEIO_HPP_
#define _OWNPRINT_HPP_
#include <bits/stdc++.h>
int mputc (int _c, FILE * __F)
{
return (--__F->_cnt >= 0)
? (int) (unsigned char) (*__F->_ptr++ = (char)_c)
: _flsbuf (_c, __F);
}
void printch(const char boynextdoor)   //输出字符
{  
    mputc(boynextdoor,stdout);
}  
void printint(const int van)     //输出整型数
{  
    if(van == 0)  
    {  
        return;  
    }  
    printint(van / 10);  
    printch((char)(van % 10 + '0'));  
}  
void printstr(const char *faq)        //输出字符串
{  
    while(*faq)  
    {  
        printch(*faq);
        faq++;  
    }  
}  
void printfloat(const float deepdarkfantasy)     //输出浮点数，小数点第5位四舍五入
{  
    int tmpint = (int)deepdarkfantasy;  
    int tmpflt = (int)(100000 * (deepdarkfantasy - tmpint));  
    if(tmpflt % 10 >= 5)  
    {  
        tmpflt = tmpflt / 10 + 1;  
    }  
    else  
    {  
        tmpflt = tmpflt / 10;  
    }  
    printint(tmpint);  
    printch('.');  
    printint(tmpflt);  
 
}  
void mprintf(const char *jvav,...)  
{  
    va_list ap;  
    va_start(ap,jvav);     //将ap指向第一个实际参数的地址
    while(*jvav)  
    {  
        if(*jvav != '%')  
        {  
            printch(*jvav);  
            jvav++;  
        }  
        else  
        {  
            jvav++;  
            switch(*jvav)  
            {  
                case 'c':  
                {  
                    char valch = va_arg(ap,int);  //记录当前实践参数所在地址
                    printch(valch);  
                    jvav++;  
                    break;  
                }  
                case 'd':  
                {  
                    int valint = va_arg(ap,int);  
                    printint(valint);  
                    jvav++;  
                    break;  
                }  
                case 's':  
                {  
                    char *valstr = va_arg(ap,char *);  
                    printstr(valstr);  
                    jvav++;  
                    break;  
                }  
                case 'f':  
                {  
                    float valflt = va_arg(ap,double);  
                    printfloat(valflt);  
                    jvav++;  
                    break;  
                }  
                default:  
                {  
                    printch(*jvav);  
                    jvav++;  
                }  
            }    
        }  
    }
    va_end(ap);         
}
#endif