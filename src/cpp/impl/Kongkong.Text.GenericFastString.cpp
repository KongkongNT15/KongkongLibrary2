namespace klib::Kongkong::Text
{
    template <CChar TChar>
    GenericFastString<TChar>::GenericFastString(
        ssize_t length,
        const ElementType* p,
        NonType
    )
        : Base(
            length,
            KLIB_NEW ElementType[length + 1]
        )
    {
        // メモリの確保失敗
        if (this->m_p == nullptr) [[unlikely]] throw MemoryAllocationException::OutOfMemory();

        // 中身をコピー
        for (ssize_t i = 0; i < length; i++) {
            this->m_p[i] = p[i];
        }

        // NULL文字を追加
        this->m_p[length] = static_cast<ElementType>('\0');
    }

    template struct GenericFastString<char>;
    template struct GenericFastString<wchar_t>;
    template struct GenericFastString<char8_t>;
    template struct GenericFastString<char16_t>;
    template struct GenericFastString<char32_t>;
}