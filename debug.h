#ifndef __DEBUG_H
#define __DEBUG_H

#include <linux/kernel.h>

#define _MODULE_NAME "lefs"

#define _INF(fmt, arg...) \
	printk(KERN_INFO _MODULE_NAME "->%s[%d]: " fmt, __FUNCTION__, __LINE__, ##arg)

#define _ERR(fmt, arg...) \
	printk(KERN_ERR _MODULE_NAME "->%s[%d]: " fmt, __FUNCTION__, __LINE__, ##arg)

#define _WRN(fmt, arg...) \
	printk(KERN_WARNING _MODULE_NAME "->%s[%d]: " fmt, __FUNCTION__, __LINE__, ##arg)

#define _DBG(fmt, arg...) \
	printk(KERN_DEBUG _MODULE_NAME "->%s[%d]: " fmt, __FUNCTION__, __LINE__, ##arg)

#define _EMERG(fmt, arg...) \
	printk(KERN_EMERG _MODULE_NAME "->%s[%d]: " fmt, __FUNCTION__, __LINE__, ##arg)

#endif // __DEBUG_H