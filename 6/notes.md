kallsyms_on_each_symbol
------------------------

Can be used to dump all the kernel symbols along with their addresses.

int kallsyms_on_each_symbol(int (*fn)(void *, const char *, struct module *,
                                      unsigned long),
                            void *data);

fn -> callback function that is called for each symbol.
	callback function has the following prototype
	int fn(void *data, const char *sym_name, struct module *module,
       unsigned long address);

data: will contain pointer to your private data you passed as last argument to kallsyms_on_each_symbol()
sym_name: will contain name of current kernel symbol
module: name of the module
address: will contain address of current kernel symbol



