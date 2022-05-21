#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

enum {
  XMAX = 10,
  YMAX = 10
};

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
} screen;

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;

  return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;

  return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);

  return temp;
}

int main(void)
{
  struct rect screen1, screen2;
  struct point middle;
  struct point p1 = { 1, 1 };
  struct point p2 = { 3, 5 };
  struct point p3 = addpoint(p1, p2);

  printf("(%d, %d) + (%d, %d) = (%d, %d)\n",
      p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

  screen1.pt1 = makepoint(0, 0);
  screen1.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint(
      (screen1.pt1.x + screen1.pt2.x) / 2,
      (screen1.pt1.y + screen1.pt2.y) / 2);
  printf("middle.x: %d, middle.y: %d\n", middle.x, middle.y);

  screen2.pt1 = makepoint(2, 1);
  screen2.pt2 = makepoint(1, 2);
  screen2 = canonrect(screen2);
  printf("pt1: (%d, %d), pt2: (%d, %d)\n",
      screen2.pt1.x, screen2.pt1.y,
      screen2.pt2.x, screen2.pt2.y);
  printf("(%d, %d) is %sincluded in the screen2\n",
      p1.x, p1.y, ptinrect(p1, screen2) ? "" : "not ");
  printf("(%d, %d) is %sincluded in the screen2\n",
      p2.x, p2.y, ptinrect(p2, screen2) ? "" : "not ");

  return 0;
}
