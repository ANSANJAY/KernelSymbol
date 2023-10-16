#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "printk";

module_param(sym_name, charp, 0);

static int __init hello_init(void)
{
    char buf[128];
    unsigned long sym_addr = kallsyms_lookup_name(sym_name);
    pr_info("Address of symbol(%s):(0x%lx)\n", sym_name, sym_addr);
    sprint_symbol(buf, sym_addr);
    pr_info("sprint_symbol returned:%s\n", buf);
    return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
