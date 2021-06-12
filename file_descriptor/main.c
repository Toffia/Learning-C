#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void *ec_malloc(unsigned int size);
void fatal(char* message);

void usage(char* prog_name, char*filename)
{
 printf("Usage: %s <data to add to %s>\n", prog_name, filename);
 exit(0);
}

int main(int argc, char *argv[])
{

 int fd; // file descriptor
 char *buffer, *datafile;
 buffer = (char*) ec_malloc(100);
 datafile = (char*) ec_malloc(20);

 strcpy(datafile,"..\\file_descriptor\\file");
 if (argc < 2)
  usage(argv[0],datafile);

 strcpy(buffer, argv[1]);

 printf("[DEBUG] buffer @ %p: \'%s\'\n",buffer,buffer);
 printf("[DEBUG] datafile @ %p: \'%s\'\n",datafile,datafile);

 strncat(buffer,"\n",1);

 fd = open(datafile, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR|S_IWUSR); // use O_APPEND to append text
 if (fd == -1)
  fatal("in main() while opening file");

 printf("[DEBUG] file descriptor: %d\n",fd);

 if (write(fd,buffer,strlen(buffer))==-1)
  fatal("in main() while writing to file");

 if (close(fd)==-1)
  fatal("in main() while closing file");

 printf("File was saved\n");

 free(buffer);
 free(datafile);
}

void fatal(char* message)
{
 char error_message[100];
 strcpy(error_message, "[!!] ERROR "); // Using strcpy to alloc stack memory for 100 chars
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

 return ptr;
}