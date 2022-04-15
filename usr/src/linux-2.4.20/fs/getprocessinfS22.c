#include<linux/getprocessinfS22.h>
#include<linux/types.h>
#include<linux/kernel.h>
#include<linux/sched.h>
#include<asm-i386/system.h>
#include<asm-i386/uaccess.h>
#include<asm-i386/current.h>
asmlinkage int sys_getprocessinfS22(int f, struct procdat *data)
{
	cli();
	struct procdat x;
	if (f <= 22 && f > 0) {
		copy_from_user(&x, data, sizeof(struct procdat));	
		x.counter = current->counter;
		x.nice = current->nice;
		x.pid = current->pid;
		x.pidparent = current->p_pptr->pid;
		x.uid = (long)current->uid;
		x.priority = current->rt_priority;
		x.state = current->state;
		x.policy = current->policy;
		x.prio = 20 - (current->policy);
		copy_to_user(data, &x, sizeof(struct procdat));
		return 0;
	}
	else if(f > 22) {
		copy_from_user(&x, data, sizeof(struct procdat));
		x.state = current->state;
		copy_to_user(data, &x, sizeof(struct procdat));
		return -1;
	}
	else {
		
		return -1;
	}
	sti();
}
