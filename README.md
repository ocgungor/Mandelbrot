Mandelbrot
==========

A simple Mandelbrot implementation written in C using X11

I have received a few complaints about X11 not being found in MacOS 10.14 and above.. I have updated the code by following the instructions on https://github.com/alexcu/swift-x11-example-xcode/blob/master/README.md. However, there is no need for a modulemap since this is written in C.

## Prerequisites
Install Quartz using [Homebrew Cask](https://github.com/caskroom/homebrew-cask) or directly from [Sourceforge](http://www.xquartz.org)

```
$ brew cask install xquartz
```
## Getting Started

Link the header files into `/usr/local/include/X11` and libraries into `/usr/local/lib/X11`:

```
$ ln -s /usr/X11/include/X11 /usr/local/include
$ ln -s /usr/X11/lib /usr/local/lib/X11
```

Screenshot
==========

![Screenshot](https://raw.github.com/ocgungor/Mandelbrot/master/Screenshot.png)


Copytight
==========

```
/*
 * Mandelbrot
 *
 * Created by Oguzhan Cansin Gungor on 18/04/13.
 *
 * Copyright (c) 2013 Aslan-Apps. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *       This product includes software developed by Aslan-Apps.
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
```
