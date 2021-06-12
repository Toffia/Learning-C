#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void *ec_malloc(unsigned int size);

void usage(char* prog_name, char*filename)
{
 printf("Usage: %s <data to add to %s>\n", prog_name, filename);
 exit(0);
}

int main()
{
 int fd; // file descriptor
 char *buffer, *datafile;

 buffer = (char*) ec_malloc(100);
 datafile = (char*) ec_malloc(20);
 strcpy(datafile,"..\\file_descriptor\\");

}

void fatal(char* message)
{
 char error_message[100];
 strcpy(error_message, "[!!] ERROR"); // Using strcpy to alloc stack memory for 100 chars
 strncat(error_message, message, 83);
 perror(error_message);
 exit(-1);
}

void *ec_malloc(unsigned int size)
{
 void *ptr;
 ptr = malloc(size);
 if (ptr == NULL)
 {
  fatal("in func ec_malloc while trying to alloc mem");
 }
}