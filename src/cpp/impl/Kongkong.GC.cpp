namespace klib::Kongkong
{
    constinit bool GC::s_isInitialized = false;
    constinit ssize_t GC::s_length = 0;
    constinit void* GC::s_pointer = nullptr;

    ErrorCode GC::Close() noexcept
    {
        if (!s_isInitialized) [[unlikely]] return ErrorCode::AlreadyClosed();

        s_isInitialized = false;

        return ErrorCode::NoError();
    }

    ErrorCode GC::Initialize(
        ssize_t blockSize
    ) noexcept
    {
        if (s_isInitialized) [[unlikely]] return ErrorCode::AlreadyInitialized();
        if (blockSize <= 0) [[unlikely]] return ErrorCode::ArgumentNonPositive();

        // 

        s_isInitialized = true;

        return ErrorCode::NoError();
    }
}