#include<linux/unistd.h>
#include<sys/types.h>
#include<errno.h>
extern int errno;
struct procdat {
	long counter;
	long nice;
	pid_t pid;
	pid_t pidparent;
	long uid;
	int priority;
	long state;
	unsigned long policy;
	long prio;
};
_syscall2(int, getprocessinfS22, int, f, struct procdat*, p);
// tutorial
