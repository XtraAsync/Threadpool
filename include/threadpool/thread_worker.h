#include "thread_pool.h"


class ThreadWorker {
private:
    int m_id;
    ThreadPool *m_pool;

public:
    ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id) {}

    void operator()();
};