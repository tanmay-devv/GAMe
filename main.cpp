#include<X11/Xlib.h>
#include <cstdio>

int main()
{	
	

	Display *d = XOpenDisplay(NULL);
	if (d==NULL) {
		printf("unable to open the display \n");
		return -1;
	}


return 0;
}
