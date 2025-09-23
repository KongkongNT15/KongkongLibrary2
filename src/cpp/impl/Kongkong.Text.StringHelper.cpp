namespace klib::Kongkong::Text
{
    template <CChar TChar>
    GenericStringMemory<TChar> StringHelper::DumpUnsafe(
        const TChar* str
    )
    {
        return DumpUnsafe<TChar>(
            GetLengthUnsafe<TChar>(str),
            str
        );
    }

    template <CChar TChar>
    GenericStringMemory<TChar> StringHelper::DumpUnsafe(
        ssize_t length,
        const TChar* str
    )
    {
        auto memory = GenericStringMemory<TChar>::AllocWithLengthUnsafe(length);

        for (ssize_t i = 0; i < length; i++) {
            memory[i] = str[i];
        }

        memory.SetNullTerminatorUnsafe();

        return memory;
    }

    template GenericStringMemory<char> StringHelper::DumpUnsafe<char>(const char*);
    template GenericStringMemory<wchar_t> StringHelper::DumpUnsafe<wchar_t>(const wchar_t*);
    template GenericStringMemory<char8_t> StringHelper::DumpUnsafe<char8_t>(const char8_t*);
    template GenericStringMemory<char16_t> StringHelper::DumpUnsafe<char16_t>(const char16_t*);
    template GenericStringMemory<char32_t> StringHelper::DumpUnsafe<char32_t>(const char32_t*);

    template GenericStringMemory<char> StringHelper::DumpUnsafe<char>(ssize_t, const char*);
    template GenericStringMemory<wchar_t> StringHelper::DumpUnsafe<wchar_t>(ssize_t, const wchar_t*);
    template GenericStringMemory<char8_t> StringHelper::DumpUnsafe<char8_t>(ssize_t, const char8_t*);
    template GenericStringMemory<char16_t> StringHelper::DumpUnsafe<char16_t>(ssize_t, const char16_t*);
    template GenericStringMemory<char32_t> StringHelper::DumpUnsafe<char32_t>(ssize_t, const char32_t*);
}