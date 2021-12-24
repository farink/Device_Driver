#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FARIN");

static int my_add(int a, int b)
{
   /* int temp;
    temp=b;
    b=a;
    a=temp;*/
    return (a + b);
}
EXPORT_SYMBOL(my_add);
static int __init hello_init(void)
{
    printk(KERN_ALERT "\nHELLO TO ALL\n");
    return 0;
}
static void __exit hello_exit(void)
{
    printk(KERN_ALERT "\n BYE TO ALL");
}
module_init(hello_init);
module_exit(hello_exit);
