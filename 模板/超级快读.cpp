template<typename type>
inline void read(type &x)
{
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag^=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
template<typename type>
inline void write(type x)
{
    x<0?x=-x,putchar('-'):0;
    static short Stack[50],top(0);
    do Stack[++top]=x%10,x/=10;while(x);
    while(top) putchar(Stack[top--]|48);
}
inline char read(char &ch){return ch=getchar();}
inline char write(const char &ch){return putchar(ch);}
template<typename type,typename ...T>
inline void read(type &x,T&...y){read(x),read(y...);}
template<typename type,typename ...T>
inline void write(type x,T...y){write(x),putchar(' '),write(y...),sizeof...(y)^1?0:putchar('\n');}
