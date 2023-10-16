kallsyms_lookup_name
---------------------

unsigned long kallsyms_lookup_name(const char *name);

This takes symbol name as argument and returns its address in memory

The calling code can dereference the pointer to make use of that symbol.

If the symbol isn’t found, the function returns NULL
