# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
# include <errno.h> 
# include <dirent.h>



int main(){
int r;
int fdin;
const char *DIRNAME = "/tmp"; 
struct dirent *entry;
r = mkdir(DIRNAME , 0777); 
if(r< 0)
{
	printf("If (r<0) - open");
}

DIR *dir= opendir(DIRNAME); 
if(dir == NULL)
{
 	printf("if(dir == NULL)");
}
while (1) {
entry = readdir(dir); 
if(entry == NULL){
int myerrno = errno; 
if(myerrno != 0)
{
	printf("if(myerrno != 0)"); 
}
else
{
break;
 }
}
printf("inode= %12d offset= %12d reclen= %6d type= %4d name= %s\n",entry->d_ino,entry->d_seekoff,entry->d_reclen,entry->d_type,entry->d_name);
}

r= closedir(dir); 
printf("r= %d\n",r); 
if(r< 0){
	printf("If (r<0) - close");
 }

}