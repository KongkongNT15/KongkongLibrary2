namespace klib::Kongkong::Threading::Async
{
    ::std::suspend_never
    Awaiter::promise_type_base::final_suspend() const noexcept
    {
        if (m_pAwaiter != nullptr) {
            m_pAwaiter->m_status = TaskStatus::Completed;

            auto other = m_pAwaiter->m_other;

            if (other != nullptr) other.resume();
        }

        return {};
    }

    void Awaiter::await_suspend(
        std::coroutine_handle<> h
    )
    {
        switch (m_status) {
            case TaskStatus::Completed:
            case TaskStatus::Faulted:
            {
                h.resume();
                break;
            }
            default:
            {
                m_other = h;
                break;
            }
        }
    }

    void Awaiter::Wait() const noexcept
    {
        using namespace ::std::chrono;

        while (m_status.load() == TaskStatus::Running) {
            ::std::this_thread::sleep_for(1ms);
        }
    }
}