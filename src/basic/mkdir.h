/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>

typedef enum MkdirFlags {
        MKDIR_FOLLOW_SYMLINK = 1 << 0,
        MKDIR_WARN_MODE      = 1 << 1,
} MkdirFlags;

int mkdir_errno_wrapper(const char *pathname, mode_t mode);
int mkdirat_errno_wrapper(int dirfd, const char *pathname, mode_t mode);
int mkdir_safe(const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags);
int mkdir_parents(const char *path, mode_t mode);
int mkdir_parents_safe(const char *prefix, const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags);
int mkdir_p(const char *path, mode_t mode);
int mkdir_p_safe(const char *prefix, const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags);

/* mandatory access control(MAC) versions */
int mkdir_safe_label(const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags);
#if 0 /// UNNEEDED by elogind
#endif // 0
int mkdir_parents_label(const char *path, mode_t mod);
int mkdir_p_label(const char *path, mode_t mode);

/* internally used */
typedef int (*mkdir_func_t)(const char *pathname, mode_t mode);
int mkdir_safe_internal(const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags, mkdir_func_t _mkdir);
int mkdir_parents_internal(const char *prefix, const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags, mkdir_func_t _mkdir);
int mkdir_p_internal(const char *prefix, const char *path, mode_t mode, uid_t uid, gid_t gid, MkdirFlags flags, mkdir_func_t _mkdir);

int mkdir_p_root(const char *root, const char *p, uid_t uid, gid_t gid, mode_t m);
