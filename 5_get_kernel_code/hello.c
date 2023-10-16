#include <linux/module.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");

//__pa_symbol macro which returns physical address of a given symbol

static int __init hello_init(void)
{
	phys_addr_t start_text = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("_text"));
	phys_addr_t end_text   = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("_etext"));
	phys_addr_t start_bss  = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("__bss_start"));
	phys_addr_t end_bss    = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("__bss_stop"));
	phys_addr_t start_data = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("_sdata"));
	phys_addr_t end_data   = (phys_addr_t)__pa_symbol(kallsyms_lookup_name("_edata"));

	pr_info("text section:%llx - %llx\n", start_text, end_text - 1);
	pr_info("data section:%llx - %llx\n", start_data, end_data - 1);
	pr_info("bss section:%llx - %llx\n", start_bss, end_bss - 1);



	return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
	
	
