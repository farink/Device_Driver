#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"K_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FARIN");

int x = 23;
int y = 55;

int __init add_init(void)
{
    printk("\nWe are in avrage function \n");
    printk("Result is:%d\n",my_add(x,y)/2);
    return 0;
}
void __exit add_exit(void)
{
    printk("\nwe are leaving \n");
}
module_init(add_init);
module_exit(add_exit);
