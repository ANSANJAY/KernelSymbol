A peek inside a LKM
------------------------

All modules have their own symbols.

Suppose we have a module hello.ko, with a lot of functions, variables and so on.

After compiling it and obtaining the module’s object file, we can get a list of its symbols by running nm

$ nm ./hello.ko

U -> Undefined
