# Device_Driver
LINUX DEVICE DRIVER


## Module parameter
**Array parameter**
-Array parameters, where the values are supplied as a comma-separated list, are also
supported by the module loader. 

-To declare an array parameter, use:module_param_array(name,type,num,perm);

-name is the name of your array (and of the parameter), type is the type of the
array elements, num is an integer variable, and perm is the usual permissions value.
