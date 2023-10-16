#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "sys_call_table";

typedef asmlinkage long (*sys_call_ptr_t)(const struct pt_regs *);
static sys_call_ptr_t *sys_call_table;


sys_call_ptr_t old_open;

static asmlinkage long my_open(const struct pt_regs *regs)
{
	char __user *filename = (char *)regs->di;
        char user_filename[256] = {0};
	long copied = strncpy_from_user(user_filename, filename, sizeof(user_filename));
	if (copied > 0)
		pr_info("%s filename:%s\n",__func__, user_filename);
	return old_open(regs);
}



static int __init hello_init(void)
{
	sys_call_table = (sys_call_ptr_t *)kallsyms_lookup_name(sym_name);
	old_open = sys_call_table[__NR_open];
	// Temporarily disable write protection
	write_cr0(read_cr0() & (~0x10000));
	sys_call_table[__NR_open] = my_open;
	// Re-enable write protection
	write_cr0(read_cr0() | 0x10000);

	return 0;
}

static void __exit hello_exit(void)
{
	// Temporarily disable write protection
	write_cr0(read_cr0() & (~0x10000));
	sys_call_table[__NR_open] = old_open;
	// Re-enable write protection
	write_cr0(read_cr0() | 0x10000);

}

module_init(hello_init);
module_exit(hello_exit);
