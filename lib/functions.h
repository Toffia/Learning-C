#include <string.h>
#include <malloc.h>
#include <stdlib.h>

void fatal(char *msg)
{
 char err_msg[100];

 strcpy(err_msg, "[!!] Critical err");
 strncat(err_msg, msg, 83);
 perror(err_msg);
 exit(-1);
}

void *ec_malloc(unsigned int size)
{
 void *ptr;
 ptr = malloc(size);
 if (ptr==NULL) fatal("in ec_malloc() while allocating mem");
 return ptr;
}