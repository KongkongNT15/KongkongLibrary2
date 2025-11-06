namespace klib::Kongkong
{
    void ErrorCode::Throw() const
    {
        switch (static_cast<s_code>(m_value)) {
        case s_code::NoError: return;

        default:return;
        }

#if KLIB_HAS_CPP23
        ::std::unreachable();
#endif
    }
}