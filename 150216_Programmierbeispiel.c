#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main() {

int i;
char s[6];


fdout = open(FILENAME, O_WRONLY | O_CREAT);

for (i=1; i < 100; i++) {
  int n = i * i;
  printf("Die Quadratzahl ist: %d \n" , n);

// Idee Brodowsky
// 
  
  sprintf(s,"%4d\n",i*i);
  m = write(fdout, (void *) s ,5);

// man 2 write ->
// write(int fildes, const void *buf, size_t nbyte);


}

return 0;

// BSP aus Unterricht
int k,m,n;
int fdout;
int fdin;
const char *FILENAME = "/tmp/out-lowlevel.txt"; const char *CONTENT = "Dies ist ein Beispieltext 2"; char *buffer;
  n = strlen(CONTENT) + 1; // include '\000'
  fdout = open(FILENAME, O_WRONLY | O_CREAT);
  printf("fdout=%d\n", fdout);
  m = write(fdout, (void *) CONTENT, n);
  close(fdout);
  printf("%d bytes written (lenght %d)\n", m, n);
  buffer = (char *) malloc(m);
  fdin = open(FILENAME, O_RDONLY);
  printf("fdin=%d\n", fdin);
  k = read(fdin, (void *) buffer, m);
  close(fdin);
  printf("%d byte read:\n%s\n", k, buffer);


}