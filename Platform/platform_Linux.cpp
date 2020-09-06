#include "platform_Linux.h"



void Platform_Linux::NewThread(void* target) {


}


void Platform_Linux::StartWindow() {

    dpy = XOpenDisplay(NULL);

    if(dpy == nullptr) {
        printf("\n\tcannot connect to X server\n\n");
        exit(0);
    }

    root = DefaultRootWindow(dpy);
    vi = glXChooseVisual(dpy, 0, att);

    if(vi == NULL) {
	    printf("\n\tno appropriate visual found\n\n");
        exit(0);
    } 
    else {
	    printf("\n\tvisual %p selected\n", (void *)vi->visualid); /* %p creates hexadecimal output like in glxinfo */
    }

    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;
    win = XCreateWindow(dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);

    XStoreName(dpy, win, "VERY SIMPLE APPLICATION");

    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);

    while(1) {
 	    XNextEvent(dpy, &xev);
        
        if(xev.type == Expose) {
        	XGetWindowAttributes(dpy, win, &gwa);
            glViewport(0, 0, gwa.width, gwa.height);
        	//Do something 
            glXSwapBuffers(dpy, win);
        }
                
	    else if(xev.type == KeyPress) {
            glXMakeCurrent(dpy, None, NULL);
 		    glXDestroyContext(dpy, glc);
 		    XDestroyWindow(dpy, win);
 		    XCloseDisplay(dpy);
 		    exit(0);
        }
    } /* this closes while(1) { */
 /* this is the } which closes int main(int argc, char *argv[]) { */
}
