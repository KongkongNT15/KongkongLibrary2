namespace klib::Kongkong::Text
{
    template <CChar TChar>
    GenericStringMemory<TChar> DumpUnsafe(
        const TChar* str
    )
    {
        return DumpUnsafe<TChar>(
            GetLengthUnsafe<TChar>(str),
            str
        );
    }

    template <CChar TChar>
    GenericStringMemory<TChar> DumpUnsafe(
        ssize_t length,
        const TChar* str
    )
    {
        auto memory = GenericStringMemory<TChar>::AllocWithLengthUnsafe(length);

        for (ssize_t i = 0; i < length; i++) {
            memory[i] = str[i];
        }

        memory[length] = static_cast<TChar>('\0');

        return memory;
    }
}