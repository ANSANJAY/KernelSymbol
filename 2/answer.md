How do you find out whether a function is static or global by looking into /proc/kallsyms?
------------------------------------------------------------------------------------------

$ cat /proc/kallsysms | grep <function_name>

$ cat /proc/kallsyms | grep msleep

If you observe 't' it is static and 'T' then it is global symbol

$ cat /proc/kallsyms | grep crc32c_mod_init 

/proc/kallsysms follows nm syntax

All exported symbols will have another symbol prefixed with __ksymtab_


