#ifndef KLIB_KONGKONG_THREADING_ASYNC_TASKSTATUS_H
#define KLIB_KONGKONG_THREADING_ASYNC_TASKSTATUS_H

namespace klib::Kongkong::Threading::Async
{
    enum struct TaskStatus {
        Completed, //
        Faulted,   //
        Running,   //
    };
}

#endif //!KLIB_KONGKONG_THREADING_ASYNC_TASKSTATUS_H