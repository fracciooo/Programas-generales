#include <graphics.h>

using namespace std;

int main()
{
	   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int midx = getmaxx() / 2;
   int midy = getmaxy() / 2;
   int radius = 100;

   circle(midx, midy, radius);

   getch();
   closegraph();
	return 0;
}
