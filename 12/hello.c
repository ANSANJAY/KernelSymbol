#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "sys_call_table";

typedef asmlinkage long (*sys_call_ptr_t)(const struct pt_regs *);
static sys_call_ptr_t *sys_call_table;
typedef asmlinkage long (*custom_open) (const char __user *filename, int flags, umode_t mode);

sys_call_ptr_t old_open;

static asmlinkage long my_open(const struct pt_regs *regs)
{
	pr_info("%s\n",__func__);
        return old_open(regs);
}

static int __init hello_init(void)
{
	sys_call_table = (sys_call_ptr_t *)kallsyms_lookup_name(sym_name);
	old_open = sys_call_table[__NR_open];
	sys_call_table[__NR_open] = my_open;

	return 0;
}

static void __exit hello_exit(void)
{
	sys_call_table[__NR_open] = old_open;

}

module_init(hello_init);
module_exit(hello_exit);
