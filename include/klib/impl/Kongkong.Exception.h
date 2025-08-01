#ifndef IMPL_KONGKONG_EXCEPTION_H
#define IMPL_KONGKONG_EXCEPTION_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.GenericString.h"

namespace klib::Kongkong
{
	/// <summary>
	/// 例外クラス
	/// </summary>
	struct Exception : public ValueType {
	private:
		/// <summary>
		/// 例外メッセージ
		/// </summary>
		String m_message;
		
	public:

		constexpr Exception(String message) noexcept;

		/// <summary>
		/// 例外メッセージを取得
		/// </summary>
		/// <returns>例外メッセージ</returns>
		[[nodiscard]] constexpr String const& Message() const noexcept;

		/// <summary>
		/// 例外メッセージを取得
		/// </summary>
		/// <returns>例外メッセージ</returns>
		[[nodiscard]] String ToString() const;
	};
}

namespace klib::Kongkong
{
	constexpr Exception::Exception(String message) noexcept
		: m_message(::std::move(message))
	{
	}

	constexpr String const& Exception::Message() const noexcept
	{
		return m_message;
	}

	inline String Exception::ToString() const
	{
		return m_message;
	}
}

#endif //!IMPL_KONGKONG_EXCEPTION_H