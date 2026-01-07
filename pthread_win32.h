#ifndef __PTHREAD_WIN32_H__
#define __PTHREAD_WIN32_H__

/* pthread emulation for windows */

#ifdef _WIN32

#include <windows.h>
#include <process.h>

#define	PTHREAD_BARRIER_SERIAL_THREAD	1

typedef struct {
	HANDLE handle;
	unsigned thread_id;
	int detached;
} pthread_t;

#if _WIN32_WINNT >= 0x0600
#define PTHREAD_MUTEX_INITIALIZER SRWLOCK_INIT
typedef SRWLOCK pthread_mutex_t;
#else
typedef CRITICAL_SECTION   pthread_mutex_t;
#endif
#define PTHREAD_COND_INITIALIZER {0}
typedef CONDITION_VARIABLE pthread_cond_t;
typedef SYNCHRONIZATION_BARRIER pthread_barrier_t;

/* thread */
int pthread_create(pthread_t *thread, void *attr, void *(*start_routine)(void *), void *arg);
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, void **retval);

/* mutex */
int pthread_mutex_init(pthread_mutex_t *mutex, void *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

/* condition variable */
int pthread_cond_init(pthread_cond_t *cond, void *attr);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_signal(pthread_cond_t *cond);

/* barrier */
int pthread_barrier_init(pthread_barrier_t *barrier, void *attr, unsigned count);
int pthread_barrier_wait(pthread_barrier_t *barrier);
int pthread_barrier_destroy(pthread_barrier_t *barrier);

#endif /* _WIN32 */

#endif /* __PTHREAD_WIN32_H__ */
