//
//  mandelbrot.c
//  Mandelbrot
//
//  Created by Oguzhan Gungor on 16/04/13.
//  Copyright (c) 2013 Oguzhan Gungor. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "mandelbrot.h"


void drawer () {
    int x,i,j,imagewidth,left = 0,outside,r,k;
	float s,realcentre,imgcentre,realx,imgx;
    
	Display* display;             /* pointer to X Display structure.           */
  	int screen_num;               /* number of screen to place the window on.  */
  	Window win;                   /* pointer to the newly created window.      */
  	unsigned int display_width, display_height;  /* height and width of the X display. */
  	unsigned int width, height;   /* height and width for the new window.      */
  	char *display_name = getenv("DISPLAY");  /* address of the X display.      */
  	GC gc;                        /* GC (graphics context) used for drawing    */
    /*  in our window.                           */
    
  	/* open connection with the X server. */
  	display = XOpenDisplay(display_name);
  	if (display == NULL) {
        fprintf(stderr, "cannot connect to X server '%s'\n",display_name);
        exit(EXIT_FAILURE);
  	}
    
  	/* get the geometry of the default screen for our display. */
 	screen_num = DefaultScreen(display);
  	display_width = DisplayWidth(display, screen_num);
  	display_height = DisplayHeight(display, screen_num);
    
  	/* make the new window occupy much of the screen's size. */
  	width = (display_width * 0.5);
  	height = (display_height * 0.5);
    // printf("window width - '%d'; height - '%d'\n", width, height);
    
  	/* create a simple window, as a direct child of the screen's   */
  	/* root window. Use the screen's white color as the background */
  	/* color of the window. Place the new window's top-left corner */
  	/* at the given 'x,y' coordinates.                             */
  	win = create_simple_window(display, width, height, 0, 0);
    
  	/* allocate a new GC (graphics context) for drawing in the window. */
  	gc = create_gc(display, win, 0);
  	XSync(display, False);
    
	k = -15;
	imagewidth = 1000;
	x = 1;


    
	r = 2;
	s = (float)(2*r)/imagewidth;
	realcentre = 0.0;
	imgcentre = 0.0;
    
	for(i=0;i<imagewidth;i++){
		for(j=0;j<imagewidth;j++){
			realx = s*(j-imagewidth/2) + realcentre;
			imgx = s*(i-imagewidth/2) + imgcentre;
			outside = testmal(realx,imgx,k);
			if (outside == 0){
                //				printf("%f %f\n",realx,imgx);
				XDrawPoint(display, win, gc, left+j/x, height/2-(imagewidth/2)/x+i/x);
				/*Flush all pending requests to the X server.*/
				XFlush(display);
			}
		}
	}
    
  	/* make a delay for a short period. */
  	sleep(300);
    
  	/* close the connection to the X server. */
  	XCloseDisplay(display);
}


int testmal(float realx, float imgx, int k) {
	int i;
	float re,im,re2,im2;
	
	re = realx;
	im = imgx;
    
	for(i=0;i<2-k;i++){
		re2 = re*re;
		im2 = im*im;
		if ((re2+im2) > 256){
			return(1);
		}
		im = 2*re*im + imgx;
		re = re2 - im2 + realx;
	}
	return(0);
}

Window create_simple_window(Display* display, int width, int height, int x, int y) {
  	int screen_num = DefaultScreen(display);
  	int win_border_width = 2;
  	Window win;
    
  	/* create a simple window, as a direct child of the screen's */
  	/* root window. Use the screen's black and white colors as   */
  	/* the foreground and background colors of the window,       */
  	/* respectively. Place the new window's top-left corner at   */
  	/* the given 'x,y' coordinates.                              */
  	win = XCreateSimpleWindow(display, RootWindow(display, screen_num),
                              x, y, width, height, win_border_width,
                              BlackPixel(display, screen_num),
                              WhitePixel(display, screen_num));
    
  	/* make the window actually appear on the screen. */
  	XMapWindow(display, win);
    
  	/* flush all pending requests to the X server. */
  	XFlush(display);
    
  	return win;
}

GC create_gc(Display* display, Window win, int reverse_video){
  	GC gc;                                /* handle of newly created GC.  */
  	unsigned long valuemask = 0;          /* which values in 'values' to  */
    /* check when creating the GC.  */
  	XGCValues values;                     /* initial values for the GC.   */
  	unsigned int line_width = 2;          /* line width for the GC.       */
  	int line_style = LineSolid;           /* style for lines drawing and  */
  	int cap_style = CapButt;              /* style of the line's edje and */
  	int join_style = JoinBevel;           /*  joined lines.               */
  	int screen_num = DefaultScreen(display);
    
  	gc = XCreateGC(display, win, valuemask, &values);
  	if (gc < 0) {
        fprintf(stderr, "XCreateGC: \n");
  	}
    
  	/* allocate foreground and background colors for this GC. */
  	if (reverse_video) {
        XSetForeground(display, gc, WhitePixel(display, screen_num));
        XSetBackground(display, gc, BlackPixel(display, screen_num));
  	}
  	else {
        XSetForeground(display, gc, BlackPixel(display, screen_num));
        XSetBackground(display, gc, WhitePixel(display, screen_num));
  	}
    
  	/* define the style of lines that will be drawn using this GC. */
  	XSetLineAttributes(display, gc,
                       line_width, line_style, cap_style, join_style);
    
  	/* define the fill style for the GC. to be 'solid filling'. */
  	XSetFillStyle(display, gc, FillSolid);
    
  	return gc;
}

