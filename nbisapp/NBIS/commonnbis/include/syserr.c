#include <stdio.h>
#include <stdlib.h>

void syserr(char *funcname, char *syscall, char *msg)
{
   (void) fflush(stdout);
   if(msg == NULL)
      (void) fprintf(stderr,"ERROR: %s: %s\n",funcname,syscall);
   else
      (void) fprintf(stderr,"ERROR: %s: %s: %s\n",funcname,syscall,msg);
   (void) fflush(stderr);

   exit(-1);
}
