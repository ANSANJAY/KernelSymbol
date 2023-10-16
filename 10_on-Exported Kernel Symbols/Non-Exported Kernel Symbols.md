**Accessing Non-Exported Kernel Symbols** 🛠️🔍

---

- **Explain the Technical Concept**:
  - In the Linux kernel, not all symbols (functions or variables) are exported. Non-exported symbols are meant to be private to the kernel and not accessible by kernel modules.
  - `kallsyms_lookup_name()` is a powerful function that can resolve symbols irrespective of whether they are exported or not.
  - However, the key point to note is that accessing non-exported symbols is risky and generally discouraged as it can lead to incompatibilities, kernel crashes, and undefined behavior.
  - Your code attempts to access `print_cpu_info()` using `kallsyms_lookup_name()`, which is feasible, but it's important to be cautious and aware of the implications.

- **Curious Questions**:
  - **Q1**: Why is accessing non-exported symbols considered risky?
    - **Answer**: Non-exported symbols are intended for internal kernel use. Their behavior, implementation, or even existence can change across kernel versions without notice, leading to module instability and incompatibility issues.
  
  - **Q2**: Is there any way to make the kernel prohibit the resolution of non-exported symbols?
    - **Answer**: Yes, the kernel can be configured with the `CONFIG_KALLSYMS_ALL` option disabled, which prevents `kallsyms_lookup_name()` from resolving non-exported symbols.
  
  - **Q3**: Why might one need to access a non-exported symbol?
    - **Answer**: While not recommended, developers might access non-exported symbols for debugging, reverse engineering, or when they need functionality that's not officially exposed by the kernel.

- **Explain in Simple Words for Memory**:
  - Imagine a library 📚 with two sections: the general section 📘 everyone can read and a restricted section 📕 behind a velvet rope. Now, you've found a magical magnifying glass 🧐 (akin to `kallsyms_lookup_name()`) that lets you read any book, even those behind the rope. While you can read the restricted books, they might be drafts, incomplete, or change often. So, if you share what you read, people might be confused if the story changes. Similarly, non-exported symbols in the kernel are like those restricted books - they're not meant for general access and might change without notice. Always handle with care! ⚠️📖.