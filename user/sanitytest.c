#include "kernel/types.h"

#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
int
main()
{
char buffer[BSIZE]; // allocate the buffer with the size of bloc

int file_descriptor = open("test.file",O_CREATE |O_WRONLY);


if(file_descriptor<0){
    printf("we have an error");
    exit(-1);
}

int counter = 0;
int max = 12 +256 +256 *256;
while(counter != max)
{
*(int*)buffer = 123;
int cur = (write(file_descriptor,buffer,sizeof(buffer)));
counter++;
if(cur<=0)
{
    break;
}
if(counter == 12){
    printf("Fi ni s h e d w ri ti n g 12KB\n");

}
if(counter == 12 + 256){
    printf("Fi ni s h e d w ri ti n g 268KB\n");
    
}


}




if(counter!=max){
    printf("error, the nuber of blocks we write is: %d\n",counter);
    exit(-1);
}
if(counter == max){
    printf("Fi ni s h e d w ri ti n g 10MB\n");
    
}
exit(0); 

}