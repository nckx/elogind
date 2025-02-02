/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>

#include "macro.h"
#include "stdio-util.h"
#include "string-util.h"

#if 0 /// UNNEEDED by elogind
#define SYS_BLOCK_PATH_MAX(suffix)                                      \
        (STRLEN("/sys/dev/block/") + DECIMAL_STR_MAX(dev_t) + 1 + DECIMAL_STR_MAX(dev_t) + strlen_ptr(suffix))
#define xsprintf_sys_block_path(buf, suffix, devno)                     \
        xsprintf(buf, "/sys/dev/block/%u:%u%s", major(devno), minor(devno), strempty(suffix))

int block_get_whole_disk(dev_t d, dev_t *ret);
int block_get_originating(dev_t d, dev_t *ret);
#endif // 0

int get_block_device(const char *path, dev_t *dev);

#if 0 /// UNNEEDED by elogind
int get_block_device_harder(const char *path, dev_t *dev);

int lock_whole_block_device(dev_t devt, int operation);

int blockdev_partscan_enabled(int fd);
#endif // 0
