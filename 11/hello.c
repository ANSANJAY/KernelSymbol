#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
char *sym_name = "print_cpu_info";
typedef void (*custom_print_cpu_info)(struct cpuinfo_x86 *c);

custom_print_cpu_info my_print, orig;

void my_print_cpu_info(struct cpuinfo_x86 *c)
{
	pr_info("%s\n", __func__);
	orig(c);
}

module_param(sym_name, charp, 0);

static int __init hello_init(void)
{
	struct cpuinfo_x86 *cpu = &cpu_data(0);
	my_print  = (custom_print_cpu_info)kallsyms_lookup_name(sym_name);

	orig = my_print; //make a backup
	my_print = my_print_cpu_info;
	my_print(cpu);
	my_print = orig;	

	return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
