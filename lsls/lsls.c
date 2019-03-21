#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // initializing variables
  DIR *d;
  struct dirent *pDirent;
  struct stat buf;
  char *fullpath;
  // open directory and assign to d; if no argv[1] value use "." instead
  d = (argc > 1) ? opendir(argv[1]) : opendir(".");
  // if there is an error, print an error message and exit function
  if (d == NULL)
  {
    perror("opendir error");
    return 0;
  }
  // looping until there are no more directory entries
  while ((pDirent = readdir(d)) != NULL) 
  {
    if (argc > 1)
    {
      // making space in memory for fullpath string
      fullpath = malloc(strlen(argv[1]) + strlen(pDirent->d_name) + 2);
      // assigning fullpath to filepath of pDirent->d_name
      sprintf(fullpath, "%s/%s", argv[1], pDirent->d_name);
      // giving buf address fullpath
      stat(fullpath, &buf);
    }
    else
    {
      fullpath = malloc(strlen(pDirent->d_name) + 3);
      sprintf(fullpath, "./%s", pDirent->d_name);
      stat(fullpath, &buf);
    }
    // printing size and name of current directory readdir(d) is providing
    printf("%lld %s\n", buf.st_size, pDirent->d_name);
    // freeing up fullpath's mallod'd space
    free(fullpath);
  }
  // close directory
  closedir(d);
  return 0;
}