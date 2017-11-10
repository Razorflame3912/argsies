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
  char ** arr = (char**)malloc(6 * sizeof(char*));
  int i = 0;
  while(line3){
    //    printf("%s\n",line2);
    arr[i] = strsep(&line3," ");
    printf("arr[%d]:\t[%s]\n",i,arr[i]);
    i++;
  }
  arr[i] = NULL;
  printf("arr[%d]:\t[%s]\n",i,arr[i]);
  return arr;
}

int main(){
  /*  char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep( &s1, "z" ));
  printf("[%s]\n", s1);*/
  char * s = "ls -a -l";
  //printf("1\n");
  char ** args = parse_args(s);
  //printf("2\n");
  int j = 0;
  //printf("3\n");
  printf("args[%d]:\t[%s]\n",0,args[0]);
  printf("args[%d]:\t[%s]\n",1,args[1]);
  printf("args[%d]:\t[%s]\n",2,args[2]);
  printf("args[%d]:\t[%s]\n",3,args[3]);

  execvp(args[0],args);
  
  return 0;
}

