namespace klib::Kongkong::Text
{
    template <CChar TChar>
    GenericFastString<TChar> GenericFastString<TChar>::Concat(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    )
    {
        GenericStringMemory<TChar> memory = GenericStringMemory<TChar>::AllocWithLengthUnsafe(left.Length() + right.Length());
    
        TChar* p = memory.Pointer();

        ::memcpy(p, left.Data(), left.Length() * sizeof(TChar));
        ::memcpy(p + left.Length(), right.Data(), right.Length() * sizeof(TChar));

        memory.SetNullTerminatorUnsafe();

        return FromMemoryUnsafe(memory);
    }

    template <CChar TChar>
    GenericFastString<TChar> GenericFastString<TChar>::Concat(
        GenericFastStringBase<TChar> const& str1,
        GenericFastStringBase<TChar> const& str2,
        GenericFastStringBase<TChar> const& str3
    )
    {
        GenericStringMemory<TChar> memory = GenericStringMemory<TChar>::AllocWithLengthUnsafe(
            str1.Length() + str2.Length() + str3.Length()
        );

        const GenericFastStringBase<TChar>* arr[]{ &str1, &str2, &str3 };

        TChar* p = memory.Pointer();

        for (const GenericFastStringBase<TChar>* pMemory : arr) {
            ::memcpy(
                p,
                pMemory->Data(),
                pMemory->Length() * sizeof(TChar)
            );
            p += pMemory->Length();
        }

        memory.SetNullTerminatorUnsafe();

        return FromMemoryUnsafe(memory);
    }

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

    template <CChar TChar>
    GenericFastString<TChar>& GenericFastString<TChar>::operator=(
        Base const& right
    )
    {
        if (right.Length() > this->m_length) return operator=(GenericFastString<TChar>(right));

        // 長さが足りている場合は再確保せずにコピーする

        ssize_t rLength = right.Length();

        for (ssize_t i = 0; i < rLength; i++) {
            this->m_p[i] = right[i];
        }

        this->m_p[rLength] = static_cast<ElementType>('\0');
        this->m_length = rLength;

        return *this;
    }

    template struct GenericFastString<char>;
    template struct GenericFastString<wchar_t>;
    template struct GenericFastString<char8_t>;
    template struct GenericFastString<char16_t>;
    template struct GenericFastString<char32_t>;
}