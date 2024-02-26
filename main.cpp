#include<X11/Xlib.h>
#include <cstdio>

#define KEY_SPACEBAR 65
#define KEY_EXIT 9
#define KEY_UP 111
#define KEY_DOWN 116
#define KEY_LEFT 113
#define KEY_RIGHT 114


namespace mygame {
class GameDisplay {
	public:
		GameDisplay();
		-GameDisplay();
	private:
		Display *display_;
		Window window_;
		int screen_;
}

GameDisplay::GameDisplay()
{
	 display_  = XOpenDisplay(NULL);
         if (display_ ==NULL) {
         	throw std::runtime_error("unable to open the display \n");
	 }
         screen_  = DefaultScreen(display); 
         window_  = XCreateSimpleWindow(display_, RootWindow(display_,screen_), 0,0,100,100,1, BlackPixel(display_,screen_), WhitePixel(display_,screen_));
	 XSelectInput(display_,window_, KeyPressMask);
	 XMapWindow(display_, window_);

}
GameDisplay::-GameDisplay()
{
	XCloseDisplay(display_);
}
}



int main()
{	
	

//	Display *d = XOpenDisplay(NULL);
//	if (d==NULL) {
//		printf("unable to open the display \n");
//		return -1;
//	}
//	int s = DefaultScreen(d);
//
//	Window w = XCreateSimpleWindow(d, RootWindow(d,s), 0,0,100,100,1, BlackPixel(d,s), WhitePixel(d,s));
//	XSelectInput(d,w, KeyPressMask);
//	XMapWindow(d, w);
	XEvent e;

	mygame::GameDisplay gd; 



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
					case KEY_SPACEBAR: printf("KEY_SPACEBAR PRESSED\n"); break;
					case KEY_EXIT: printf("ESCAPE KEY PRESSED\n"); done = true; XCloseDisplay(d);  break;
				}
			}	

		}	
	
	}

	getchar();

return 0;
}
