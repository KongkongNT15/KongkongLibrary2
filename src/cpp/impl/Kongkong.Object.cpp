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

        delete m_p;
    }

    void Object::SetInstance(ImplType* p) noexcept
    {
        if (p == nullptr) [[unlikely]] throw MemoryAllocationException::OutOfMemory();

        m_p.m_p = p;
    }

    void Object::SetInstanceWithAddRef(ImplType* p) noexcept
    {
        if (p == nullptr) [[unlikely]] throw MemoryAllocationException::OutOfMemory();

        if (p->ReferenceCount() == RefCounter::NonDeleteCount()) return;

        p->m_counter.operator++();

        m_p.m_p = p;
    }
}