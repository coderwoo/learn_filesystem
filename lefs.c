#include <linux/module.h>
#include <linux/fs.h>
#include <linux/pagemap.h>
#include <linux/mount.h>
#include <linux/init.h>
#include <linux/namei.h>
#include "debug.h"

#define LEFS_MAGIC 0x64668735

static int lefs_fill_super(
	struct super_block *sb, void *data, int silent)
{
	static struct tree_descr debug_files[] = {{ "" }};
	return simple_fill_super(sb, LEFS_MAGIC, debug_files);
}

static struct super_block *lefs_get_sb(
	struct file_system_type *fs_type,
	int flags, const char *dev_name, void *data, struct vfsmount *mnt)
{
	_INF("dev_name=%s, flags=%d\n", dev_name, flags);
	return get_sb_single(fs_type, flags, data, lefs_fill_super, mnt);
}

static struct file_system_type lefs_fs_type = {
	.owner = THIS_MODULE,
	.name = "lefs",
	.get_sb = lefs_get_sb, 
	.kill_sb =  NULL,
};

static int __init lefs_init(void)
{
	int retval = 0;
	retval = register_filesystem(&lefs_fs_type);
	if (!retval) {
		_INF("register successed!\n");
	}
	else {
		_INF("regiser failed!\n");
	}
	return retval;
}

static void __exit lefs_exit(void)
{
	_INF("exit\n");
	unregister_filesystem(&lefs_fs_type);
}

module_init(lefs_init);
module_exit(lefs_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("lefs: learn file system");
MODULE_VERSION("0.1");