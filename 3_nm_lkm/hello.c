#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

int global_var = 10;
static int static_var = 11;

static void static_fn(void)
{
	pr_info("%s\n", __func__);
	static_var++;
}

void global_fn(void)
{
	pr_info("%s\n", __func__);
	global_var++;
}

static int __init hello_init(void)
{
        int local_var = 0;
	pr_info("%s\n", __func__);
	local_var++;
	static_fn();
	global_fn();
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("%s\n", __func__);
}

module_init(hello_init);
module_exit(hello_exit);
