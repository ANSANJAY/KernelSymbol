#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "sys_call_table";

module_param(sym_name, charp, 0);

static int __init hello_init(void)
{
    unsigned long sym_addr = kallsyms_lookup_name(sym_name);
    pr_info("Address of symbol(%s):(0x%lx)\n", sym_name, sym_addr);
    return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
