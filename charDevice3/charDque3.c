#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>        //FOR THE CHARACTER DRIVER SUPPORT
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("farin");

dev_t a=0;


static int __init chardevice_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
     if (alloc_chrdev_region(&a,0,1,"MY_DEVICE")<0)
     {
     printk(KERN_ALERT "Cannot allocate the Major Number\n");
     return -1;
     }
     printk(KERN_ALERT"Major Number= %d \n Minor number = %d \n", MAJOR(a),MINOR(a));
     return 0;
}
static void __exit chardevice_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    unregister_chrdev_region(a, 1);

}
module_init(chardevice_init);
module_exit(chardevice_exit);
