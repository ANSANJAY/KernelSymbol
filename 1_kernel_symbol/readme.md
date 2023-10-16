**Kernel Symbols** 🧠💡

- **Concept**:
  - A *symbol* in the context of the kernel represents either a variable or a function.
  - In essence, it's a designated name corresponding to a memory space. This space can either store data (if it's a variable) or instructions (if it's a function).
  - The visibility and availability of kernel symbols vary depending on their declaration and are categorized into three primary levels:
    - **static**: Confined within its source file.
    - **extern**: Open to any code built directly into the kernel.
    - **exported**: Not just visible, but also accessible to any loadable module. This accessibility is granted using `EXPORT_SYMBOL()` and `EXPORT_SYMBOL_GPL()` macros.

- **Curious Questions**:
  - **Q1**: What's the main difference between `extern` and `exported` kernel symbols?
    - **Answer**: While both `extern` and `exported` symbols are visible across the kernel, only `exported` symbols are accessible to loadable modules.
    
  - **Q2**: Why might a developer decide to use `EXPORT_SYMBOL_GPL()` instead of just `EXPORT_SYMBOL()`?
    - **Answer**: The `EXPORT_SYMBOL_GPL()` macro is used when the developer wishes to restrict the usage of the exported symbol only to modules that are GPL-compatible. It's a way of ensuring license compatibility.
  
  - **Q3**: How does `/proc/kallsyms` differ from `System.map` in terms of the symbols they contain?
    - **Answer**: `System.map` only contains symbols from code built into the kernel. In contrast, `/proc/kallsyms` includes symbols both from the built-in kernel code as well as from the loadable kernel modules.

- **In Simple words**:
  - Think of kernel symbols like labels on boxes in a warehouse. 📦💼
    - A *static* label is a secret one - only workers in a specific section of the warehouse know about it.
    - An *extern* label is more common. All the workers in the warehouse know about it.
    - An *exported* label is broadcasted to everyone, even to temporary workers (like loadable modules in our kernel analogy). Some of these labels are restricted only for those who follow specific rules, and that's where `EXPORT_SYMBOL_GPL()` comes in.
  - Now, about our directories of labels: 📖🔍
    - `System.map` is the original directory with only permanent warehouse labels.
    - `/proc/kallsyms` is a more extensive directory that includes both permanent warehouse labels and those of temporary sections (modules).
