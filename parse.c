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
  char * line2 = (char*)malloc(200);
  char * line3 = strcpy(line2, line);
  char ** arr = (char**)malloc(6 * sizeof(char*));
  int i = 0;
  while(line3){
    arr[i] = strsep(&line3," ");
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
  char s[200] = "ls -a -l";
  char ** args = parse_args(s);
  int j = 0;
  execvp(args[0],args);
  
  return 0;
}

