Can i find the size of the function?
----------------------------------------

Yes, using sprint_symbol

int sprint_symbol(char *buffer, unsigned long address);

This function looks up a kernel symbol with 'address' and stores its 
	name
	offset
	size
	module name to
buffer

If no symbol was found just saves its 'address' as is.

This function returns the number of bytes stored in 'buffer'

symbol_name+offset/size [module_name]

