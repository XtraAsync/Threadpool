#include "threadpool/thread_worker.h"
#include "threadpool/thread_pool.h"

void ThreadWorker::operator()() {
    std::function<void()> func;
    bool dequeued;
    while (!m_pool->m_shutdown) {
        {
            std::unique_lock<std::mutex> lock(
                m_pool->m_conditional_mutex);
            if (m_pool->m_queue.empty()) {
                m_pool->m_conditional_lock.wait(lock);
            }
            dequeued = m_pool->m_queue.dequeue(func);
        }
        if (dequeued) {
            func();
        }
    }
}