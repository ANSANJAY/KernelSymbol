#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");


static int print_symbol(void *data, const char *symbol_name,
                               struct module *module, unsigned long address)
{
    pr_info("Module Name:%s \t Symbol:%s\tAddress:%lx\n", module->name, symbol_name, address);
    return 0;
}


static int __init hello_init(void)
{
	kallsyms_on_each_symbol(print_symbol, NULL);
	return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
	
	
