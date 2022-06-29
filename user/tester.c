#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(int argc, char** argv){

    symlink("a", "b");
    symlink("b", "a");
    int ref_fd;
    if ((ref_fd=open("a", O_RDWR)) == -1){
        printf("Test Passed - Can't open a symbolic link with more than 31 references\n");
    }
    else{
        printf("Test Failed - Shouldn't open a symbolic link with more than 31 references\n");
        close(ref_fd);
    }
    unlink("a");
    unlink("b");
    
    exit(0);
}