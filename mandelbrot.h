//
//  mandelbrot.h
//  Mandelbrot
//
//  Created by Oguzhan Gungor on 16/04/13.
//  Copyright (c) 2013 Oguzhan Gungor. All rights reserved.
//

#ifndef Mandelbrot_mandelbrot_h
#define Mandelbrot_mandelbrot_h
#include <X11/Xlib.h>


int testmal(float,float,int);
Window create_simple_window(Display *,int,int,int,int);
GC create_gc(Display *,Window,int);
void drawer();

#endif
