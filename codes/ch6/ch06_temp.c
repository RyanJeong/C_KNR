#ifdef A

#define LEN 10

char	  name[LEN];
char	  addr[LEN];
int    	id;
double	pay;


#endif
#ifndef B
struct point {
    int x;
    int y;
};

struct { ... } x, y, z;
/* is is syntactically analogous to */
int x, y, z;

struct point pt;

struct point {
  int x;
  int y;
} pt1;

struct {
    int x;
    int y;
} pt2;

struct point maxpt = { 320, 200 };


#endif