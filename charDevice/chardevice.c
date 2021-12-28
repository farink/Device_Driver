#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>        //FOR THE CHARACTER DRIVER SUPPORT
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("farin");


static int my_open(struct inode *pinode , struct file *pfile);
//static ssize_t my_read(struct file *pfile, char __user *buf, size_t lenght, loff_t *offset);
//static ssize_t my_write(struct file *pfile, char __user *buf, size_t lenght, loff_t *offset);
static int my_release(struct inode *pinode , struct file *pfile);


//to hold the file operations performed on this device
struct file_operations fops = {
	.owner		=	THIS_MODULE,
	.open		= 	my_open,
	.release	=	my_release,
	};
	
	int my_open(struct inode *pinode , struct file *pfile)
	{
		printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
		return 0;
	}
	
	int my_release(struct inode *pinode , struct file *pfile)
	{
		printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
		return 0;
	}
	
   
    

static int __init chardevice_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
     register_chrdev(8,"First char Driver", &fops);
    return 0;
}
static void __exit chardevice_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    unregister_chrdev(8, "First char Driver");

}
module_init(chardevice_init);
module_exit(chardevice_exit);
