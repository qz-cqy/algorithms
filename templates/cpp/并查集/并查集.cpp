#ifndef BingChaJi
#define BingChaJi

namespace bcg
{
  const int MAXN = 100001;
  int fa[MAXN];
  inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
  inline bool comb(int x, int y)
  {
    int f1 = find(x), f2 = find(y);
    if(f1 == f2) return false;
    fa[f1] = f2;
    return true;
  }
  inline bool query(int x, int y) {return find(x) == find(y);}
};

#endif
