//
// Created by hariharan on 8/16/22.
//
#include <cpp-logger/logger.h>
#include <dftracer/brahma/posix.h>

static ConstEventType CATEGORY = "POSIX";

std::shared_ptr<brahma::POSIXDFTracer> brahma::POSIXDFTracer::instance =
    nullptr;
bool brahma::POSIXDFTracer::stop_trace = false;
int brahma::POSIXDFTracer::open(const char *pathname, int flags, ...) {
  BRAHMA_MAP_OR_FAIL(open);
  DFT_LOGGER_START(pathname);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    DFT_LOGGER_UPDATE(mode)
    ret = __real_open(pathname, flags, mode);
  } else {
    ret = __real_open(pathname, flags);
  }
  DFT_LOGGER_UPDATE(flags)
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  if (trace) this->trace(ret, pathname);
  return ret;
}

int brahma::POSIXDFTracer::close(int fd) {
  BRAHMA_MAP_OR_FAIL(close);
  DFT_LOGGER_START(fd);
  int ret = __real_close(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  if (trace) this->remove_trace(fd);
  return ret;
}

ssize_t brahma::POSIXDFTracer::write(int fd, const void *buf, size_t count) {
  BRAHMA_MAP_OR_FAIL(write);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  ssize_t ret = __real_write(fd, buf, count);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::read(int fd, void *buf, size_t count) {
  BRAHMA_MAP_OR_FAIL(read);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  ssize_t ret = __real_read(fd, buf, count);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

off_t brahma::POSIXDFTracer::lseek(int fd, off_t offset, int whence) {
  BRAHMA_MAP_OR_FAIL(lseek);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(offset);
  DFT_LOGGER_UPDATE(whence);
  ssize_t ret = __real_lseek(fd, offset, whence);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::creat64(const char *path, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(creat64);
  DFT_LOGGER_START(path);
  DFT_LOGGER_UPDATE(mode);
  int ret = __real_creat64(path, mode);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  if (trace) this->trace(ret, path);
  return ret;
}

int brahma::POSIXDFTracer::open64(const char *path, int flags, ...) {
  BRAHMA_MAP_OR_FAIL(open64);
  DFT_LOGGER_START(path);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    DFT_LOGGER_UPDATE(mode)
    ret = __real_open64(path, flags, mode);
  } else {
    ret = __real_open64(path, flags);
  }
  DFT_LOGGER_UPDATE(flags)
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  if (trace) this->trace(ret, path);
  return ret;
}

off64_t brahma::POSIXDFTracer::lseek64(int fd, off64_t offset, int whence) {
  BRAHMA_MAP_OR_FAIL(lseek64);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(offset);
  DFT_LOGGER_UPDATE(whence);
  off64_t ret = __real_lseek64(fd, offset, whence);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::pread(int fd, void *buf, size_t count,
                                     off_t offset) {
  BRAHMA_MAP_OR_FAIL(pread);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  DFT_LOGGER_UPDATE(offset);
  ssize_t ret = __real_pread(fd, buf, count, offset);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::pread64(int fd, void *buf, size_t count,
                                       off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pread64);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  DFT_LOGGER_UPDATE(offset);
  ssize_t ret = __real_pread64(fd, buf, count, offset);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::pwrite(int fd, const void *buf, size_t count,
                                      off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pwrite);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  DFT_LOGGER_UPDATE(offset);
  ssize_t ret = __real_pwrite(fd, buf, count, offset);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::pwrite64(int fd, const void *buf, size_t count,
                                        off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pwrite64);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(count);
  DFT_LOGGER_UPDATE(offset);
  ssize_t ret = __real_pwrite64(fd, buf, count, offset);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::fsync(int fd) {
  BRAHMA_MAP_OR_FAIL(fsync);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  int ret = __real_fsync(fd);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::fdatasync(int fd) {
  BRAHMA_MAP_OR_FAIL(fdatasync);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  int ret = __real_fdatasync(fd);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::openat(int dirfd, const char *pathname, int flags,
                                  ...) {
  BRAHMA_MAP_OR_FAIL(openat);
  DFT_LOGGER_START(dirfd);
  DFT_LOGGER_UPDATE(dirfd);
  DFT_LOGGER_UPDATE(flags);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    DFT_LOGGER_UPDATE(mode);
    ret = __real_openat(dirfd, pathname, flags, mode);
  } else {
    ret = __real_openat(dirfd, pathname, flags);
  }
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  if (trace) this->trace(ret, pathname);
  return ret;
}

void *brahma::POSIXDFTracer::mmap(void *addr, size_t length, int prot,
                                  int flags, int fd, off_t offset) {
  BRAHMA_MAP_OR_FAIL(mmap);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(length);
  DFT_LOGGER_UPDATE(flags);
  DFT_LOGGER_UPDATE(offset);
  DFT_LOGGER_UPDATE(fd);
  void *ret = __real_mmap(addr, length, prot, flags, fd, offset);
  DFT_LOGGER_END();
  return ret;
}

void *brahma::POSIXDFTracer::mmap64(void *addr, size_t length, int prot,
                                    int flags, int fd, off64_t offset) {
  BRAHMA_MAP_OR_FAIL(mmap64);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(length);
  DFT_LOGGER_UPDATE(flags);
  DFT_LOGGER_UPDATE(offset);
  DFT_LOGGER_UPDATE(fd);
  void *ret = __real_mmap64(addr, length, prot, flags, fd, offset);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__xstat(int vers, const char *path,
                                   struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__xstat);
  DFT_LOGGER_START(path);
  int ret = __real___xstat(vers, path, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__xstat64(int vers, const char *path,
                                     struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__xstat64);
  DFT_LOGGER_START(path);
  int ret = __real___xstat64(vers, path, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__lxstat(int vers, const char *path,
                                    struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__lxstat);
  DFT_LOGGER_START(path);
  int ret = __real___lxstat(vers, path, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__lxstat64(int vers, const char *path,
                                      struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__lxstat64);
  DFT_LOGGER_START(path);
  int ret = __real___lxstat64(vers, path, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__fxstat(int vers, int fd, struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__fxstat);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  int ret = __real___fxstat(vers, fd, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::__fxstat64(int vers, int fd, struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__fxstat64);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  int ret = __real___fxstat64(vers, fd, buf);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::mkdir(const char *pathname, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(mkdir);
  DFT_LOGGER_START(pathname);
  DFT_LOGGER_UPDATE(mode);
  int ret = __real_mkdir(pathname, mode);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::rmdir(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(rmdir);
  DFT_LOGGER_START(pathname);
  int ret = __real_rmdir(pathname);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::chdir(const char *path) {
  BRAHMA_MAP_OR_FAIL(chdir);
  DFT_LOGGER_START(path);
  int ret = __real_chdir(path);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::link(const char *oldpath, const char *newpath) {
  BRAHMA_MAP_OR_FAIL(link);
  DFT_LOGGER_START(oldpath);
  DFT_LOGGER_UPDATE(newpath);
  int ret = __real_link(oldpath, newpath);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::linkat(int fd1, const char *path1, int fd2,
                                  const char *path2, int flag) {
  BRAHMA_MAP_OR_FAIL(linkat);
  DFT_LOGGER_START(fd1);
  DFT_LOGGER_UPDATE(fd1);
  DFT_LOGGER_UPDATE(fd2);
  DFT_LOGGER_UPDATE(path2);
  DFT_LOGGER_UPDATE(flag);
  int ret = __real_linkat(fd1, path1, fd2, path2, flag);
  DFT_LOGGER_UPDATE(ret);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::unlink(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(unlink);
  DFT_LOGGER_START(pathname);
  int ret = __real_unlink(pathname);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::symlink(const char *path1, const char *path2) {
  BRAHMA_MAP_OR_FAIL(symlink);
  DFT_LOGGER_START(path1);
  DFT_LOGGER_UPDATE(path2);
  int ret = __real_symlink(path1, path2);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::symlinkat(const char *path1, int fd,
                                     const char *path2) {
  BRAHMA_MAP_OR_FAIL(symlinkat);
  DFT_LOGGER_START(path1);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(path2);
  int ret = __real_symlinkat(path1, fd, path2);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::readlink(const char *path, char *buf,
                                        size_t bufsize) {
  BRAHMA_MAP_OR_FAIL(readlink);
  DFT_LOGGER_START(path);
  DFT_LOGGER_UPDATE(bufsize);
  ssize_t ret = __real_readlink(path, buf, bufsize);
  DFT_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDFTracer::readlinkat(int fd, const char *path, char *buf,
                                          size_t bufsize) {
  BRAHMA_MAP_OR_FAIL(readlinkat);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(bufsize);
  ssize_t ret = __real_readlinkat(fd, path, buf, bufsize);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::rename(const char *oldpath, const char *newpath) {
  BRAHMA_MAP_OR_FAIL(rename);
  DFT_LOGGER_START(oldpath);
  DFT_LOGGER_UPDATE(newpath);
  int ret = __real_rename(oldpath, newpath);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::chmod(const char *path, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(chmod);
  DFT_LOGGER_START(path);
  DFT_LOGGER_UPDATE(mode);
  int ret = __real_chmod(path, mode);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::chown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_MAP_OR_FAIL(chown);
  DFT_LOGGER_START(path);
  DFT_LOGGER_UPDATE(owner);
  DFT_LOGGER_UPDATE(group);
  int ret = __real_chown(path, owner, group);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::lchown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_MAP_OR_FAIL(lchown);
  DFT_LOGGER_START(path);
  DFT_LOGGER_UPDATE(owner);
  DFT_LOGGER_UPDATE(group);
  int ret = __real_lchown(path, owner, group);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::utime(const char *filename, const utimbuf *buf) {
  BRAHMA_MAP_OR_FAIL(utime);
  DFT_LOGGER_START(filename);
  int ret = __real_utime(filename, buf);
  DFT_LOGGER_END();
  return ret;
}

DIR *brahma::POSIXDFTracer::opendir(const char *name) {
  BRAHMA_MAP_OR_FAIL(opendir);
  DFT_LOGGER_START(name);
  DFT_LOGGER_UPDATE(name);
  DIR *ret = __real_opendir(name);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::fcntl(int fd, int cmd, ...) {
  BRAHMA_MAP_OR_FAIL(fcntl);
  if (cmd == F_DUPFD || cmd == F_DUPFD_CLOEXEC || cmd == F_SETFD ||
      cmd == F_SETFL || cmd == F_SETOWN) {  // arg: int
    va_list arg;
    va_start(arg, cmd);
    int val = va_arg(arg, int);
    va_end(arg);
    DFT_LOGGER_START(fd);
    DFT_LOGGER_UPDATE(fd);
    DFT_LOGGER_UPDATE(cmd);
    int ret = __real_fcntl(fd, cmd, val);
    DFT_LOGGER_END();
    return ret;
  } else if (cmd == F_GETFD || cmd == F_GETFL || cmd == F_GETOWN) {
    DFT_LOGGER_START(fd);
    DFT_LOGGER_UPDATE(fd);
    DFT_LOGGER_UPDATE(cmd);
    int ret = __real_fcntl(fd, cmd);
    DFT_LOGGER_END();
    return ret;
  } else if (cmd == F_SETLK || cmd == F_SETLKW || cmd == F_GETLK) {
    va_list arg;
    va_start(arg, cmd);
    struct flock *lk = va_arg(arg, struct flock *);
    va_end(arg);
    DFT_LOGGER_START(fd);
    DFT_LOGGER_UPDATE(fd);
    DFT_LOGGER_UPDATE(cmd);
    int ret = __real_fcntl(fd, cmd, lk);
    DFT_LOGGER_END();
    return ret;
  } else {  // assume arg: void, cmd==F_GETOWN_EX || cmd==F_SETOWN_EX
            // ||cmd==F_GETSIG || cmd==F_SETSIG)
    DFT_LOGGER_START(fd);
    DFT_LOGGER_UPDATE(fd);
    DFT_LOGGER_UPDATE(cmd);
    int ret = __real_fcntl(fd, cmd);
    DFT_LOGGER_END();
    return ret;
  }
}

int brahma::POSIXDFTracer::dup(int oldfd) {
  BRAHMA_MAP_OR_FAIL(dup);
  DFT_LOGGER_START(oldfd);
  int ret = __real_dup(oldfd);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::dup2(int oldfd, int newfd) {
  BRAHMA_MAP_OR_FAIL(dup2);
  DFT_LOGGER_START(oldfd);
  int ret = __real_dup2(oldfd, newfd);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::mkfifo(const char *pathname, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(mkfifo);
  DFT_LOGGER_START(pathname);
  DFT_LOGGER_UPDATE(mode);
  int ret = __real_mkfifo(pathname, mode);
  DFT_LOGGER_END();
  return ret;
}

mode_t brahma::POSIXDFTracer::umask(mode_t mask) {
  BRAHMA_MAP_OR_FAIL(umask);
  DFT_LOGGER_START(mask);
  mode_t ret = __real_umask(mask);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::access(const char *path, int amode) {
  BRAHMA_MAP_OR_FAIL(access);
  DFT_LOGGER_START(path);
  int ret = __real_access(path, amode);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::faccessat(int fd, const char *path, int amode,
                                     int flag) {
  BRAHMA_MAP_OR_FAIL(faccessat);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  int ret = __real_faccessat(fd, path, amode, flag);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::remove(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(remove);
  DFT_LOGGER_START(pathname);
  int ret = __real_remove(pathname);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::truncate(const char *pathname, off_t length) {
  BRAHMA_MAP_OR_FAIL(truncate);
  DFT_LOGGER_START(pathname);
  DFT_LOGGER_UPDATE(length);
  int ret = __real_truncate(pathname, length);
  DFT_LOGGER_END();
  return ret;
}

int brahma::POSIXDFTracer::ftruncate(int fd, off_t length) {
  BRAHMA_MAP_OR_FAIL(ftruncate);
  DFT_LOGGER_START(fd);
  DFT_LOGGER_UPDATE(fd);
  DFT_LOGGER_UPDATE(length);
  int ret = __real_ftruncate(fd, length);
  DFT_LOGGER_END();
  return ret;
}
