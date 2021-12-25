#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FARIN");

int my_add(int a, int b)
{
return (a+b);
}
EXPORT_SYMBOL_GPL(my_add);
int __init hello_init(void)
{
printk(KERN_ALERT "HELLO TO ALL\n");
return 0;

}
void __exit hello_exit(void)
{
printk(KERN_ALERT"Bye");
}
module_init(hello_init);
module_exit(hello_exit);
