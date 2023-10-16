Can i update the symbol address
--------------------------------

Just like read, you can also write to a symbol's address.

Note: Be careful, some addresses are in rodata section or text section, which cannot be written

If you try to write to a readonly address, you will probably get a kernel oops


