#include "lib/functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char* prog_name, char*filename)
{
 printf("Usage: %s <data to add to %s>\n", prog_name, filename);
 exit(0);
}

int main(int argc, char *argv[])
{
 int user_id, fd; // file descriptor
 char *buffer, *datafile;
 buffer = (char*) ec_malloc(100);
 datafile = (char*) ec_malloc(20);
 strcpy(datafile,"./file_descriptor/file");
 if (argc < 2)
  usage(argv[0],datafile);

 strcpy(buffer, argv[1]);

 printf("[DEBUG] buffer @ %p: \'%s\'\n",buffer,buffer);
 printf("[DEBUG] datafile @ %p: \'%s\'\n",datafile,datafile);

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

