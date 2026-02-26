#ifndef ERR_H
#define ERR_H

#define MAXLINE 4096

#define FILE_MODE ( S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH )
#define DIR_MODE ( FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH )

// Error
void err_ret(const char* fmt, ...);
void err_sys(const char* fmt, ...);
void err_cont(int error, const char* fmt, ...);
void err_exit(int error, const char* fmt, ...);
void err_dump(const char* fmt, ...);
void err_msg(const char* fmt, ...);
void err_quit(const char* fmt, ...);

// Log
void log_open(const char* ident, int option, int facility);
void log_ret(const char *fmt, ...);
void log_sys(const char *fmt, ...);
void log_msg(const char *fmt, ...);
void log_quit(const char *fmt, ...);
void log_exit(int error, const char *fmt, ...);

#endif // ERR_H
