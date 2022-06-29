#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 3 && argc != 4){
    printf("%d",argc);
    fprintf(2, "Usage: ln old new\n");
    exit(1);
  }
   if(argc == 4){//soft link ??? ln -s ls x
    if(strcmp(argv[1],"-s") == 0 &&      symlink(argv[2],argv[3]) < 0){

      fprintf(2, "symlink:  - faield");
    }
    exit(0);
  }
  if(link(argv[1], argv[2]) < 0)
    fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  exit(0);
}
