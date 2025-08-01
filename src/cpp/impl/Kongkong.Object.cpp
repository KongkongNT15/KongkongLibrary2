namespace klib::Kongkong
{
    uint64_t Object::RefCounter::operator++() noexcept
    {
        return ++m_refCount;
    }

    uint64_t Object::RefCounter::operator--() noexcept
    {
        return --m_refCount;
    }

    inline Object::Pointer::Pointer(Object::Pointer const& right) noexcept
        : m_p(right.m_p)
    {
        if (m_p != nullptr) m_p->m_counter.operator++();
    }

    Object::Pointer::~Pointer()
    {
        // NULLならなにもしない
        if (m_p == nullptr) return;

        // この場合はdeleteしてはいけない
        if (m_p->ReferenceCount() == RefCounter::NonDeleteCount()) return;


    }
}