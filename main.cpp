#include<X11/Xlib.h>
#include <cstdio>

#define KEY_EXIT 9
#define KEY_UP 111
#define KEY_DOWN 116
#define KEY_LEFT 113
#define KEY_RIGHT 114



int main()
{	
	

	Display *d = XOpenDisplay(NULL);
	if (d==NULL) {
		printf("unable to open the display \n");
		return -1;
	}
	int s = DefaultScreen(d);

	Window w = XCreateSimpleWindow(d, RootWindow(d,s), 0,0,100,100,1, BlackPixel(d,s), WhitePixel(d,s));
	XSelectInput(d,w, KeyPressMask);
	XMapWindow(d, w);
	XEvent e;

	bool done = false;

	while(!done)
	{
		if(XPending(d))
		{
			XNextEvent(d,&e);
			printf("EVENT TYPE: %d\n", e.type);
			
			if (e.type == KeyPress)
			{
				printf("key pressed: %d\n", e.xkey.keycode);
				switch (e.xkey.keycode)
				{
					case KEY_UP: printf("KEY_UP PRESSED\n"); break;
					case KEY_DOWN: printf("KEY_DOWN PRESSED\n"); break;
					case KEY_LEFT: printf("KEY_LEFT PRESSED\n"); break;
					case KEY_RIGHT: printf("KEY_RIGHT PRESSED\n"); break;
					case KEY_EXIT: printf("ESCAPE KEY PRESSED\n"); done = true; XCloseDisplay(d);  break;
				}
			}	

		}	
	
	}

	getchar();
	

return 0;
}
