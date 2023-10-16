#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "printk";
typedef int (*custom_printk)(const char *fmt, ...);


module_param(sym_name, charp, 0);

static int __init hello_init(void)
{
    custom_printk my_printk  = (custom_printk)kallsyms_lookup_name(sym_name);
    my_printk("%s\n", __func__);
    my_printk(KERN_INFO"%s\n", __func__);
    return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
