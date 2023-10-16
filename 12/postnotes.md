In Intel x86 CPUs, the Control Register CR0 has a special bit (called Write Protect bit), to control whether the CPU can write to read-only pages while running in privilege level 0

syscall table is inside a page that is read-only, and by default the "Write Protect" bit is set, you are prevented from writing to it.

In order to update the syscall correctly you will need to disable write protection by setting the "Write Protect" bit of the CR0 register to 0 before overwriting the table entry, and re-enable it after you're done
