obj-m := Add.o
KERNELDIR := /lib/modules/$(shell uname -r)/build/
PWD := $(shell pwd)
all:
	make -C $(KERNELDIR) M=$(PWD) modules
install:
	make -C $(KERNELDIR) M=$(PWD) modules_install
	depmod -a
clean:
	make -C $(KERNELDIR) M=$(PWD) clean

