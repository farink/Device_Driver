#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"K_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FARIN");

static int x = 23;
static int y = 55;

static int __init add_init(void)
{
    printk("\nWe are in adding function \n");
    printk("Result after adding is:%d\n",my_add(x,y));
    return 0;
}
static void __exit add_exit(void)
{
    printk("\nwe are leaving \n");
}
module_init(add_init);
module_exit(add_exit);
