#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("farin");

static char* charvar = "module";
static int intvar = 10;

module_param(charvar, charp, S_IRUGO);
module_param(intvar, int, S_IRUGO);

static int __init param_init(void)
{
    printk(KERN_ALERT "\nwe are in init function\n");
    printk(KERN_ALERT "\nthe value of charvar is %s \n", charvar);
    return 0;
}

static void __exit param_exit(void)
{
    printk(KERN_ALERT"\n GOOD BYE\n");

}

module_init(param_init);
module_exit(param_exit);
