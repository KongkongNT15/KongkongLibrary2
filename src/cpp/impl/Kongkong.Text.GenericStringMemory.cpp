namespace klib::Kongkong::Text
{
    template <CChar TChar>
    GenericStringMemory<TChar> GenericStringMemory<TChar>::AllocWithCapacityUnsafe(
        ssize_t capacity
    )
    {
        TChar* p = KLIB_NEW TChar[capacity];

        if (p == nullptr) [[unlikely]] throw MemoryAllocationException::OutOfMemory();

        return GenericStringMemory<TChar>(
            capacity,
            p
        );
    }

    template struct GenericStringMemory<char>;
    template struct GenericStringMemory<wchar_t>;
    template struct GenericStringMemory<char8_t>;
    template struct GenericStringMemory<char16_t>;
    template struct GenericStringMemory<char32_t>;
}