#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

char ** parse_args (char * line){
  //printf("%s\n",line);
  char line2[200];
  char * line3 = strcpy(line2, line);
  char ** arr = malloc(6 * sizeof(char*));
  int i = 0;
  while(line3){
    //    printf("%s\n",line2);
    arr[i] = strsep(&line3," ");
    printf("%s\n",line3);
    i++;
  }
  arr[i] = NULL;
  return arr;
}

int main(){
  /*  char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep( &s1, "z" ));
  printf("[%s]\n", s1);*/
  char * s = "ls -a -l";
  char ** args = parse_args(s);
  execvp(args[0],args);
  
  return 0;
}

