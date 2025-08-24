#ifndef IMPL_KONGKONG_MEMORYALLOCATIONEXCEPTION_H
#define IMPL_KONGKONG_MEMORYALLOCATIONEXCEPTION_H

#include "base.h"
#include "Kongkong.Exception.h"
#include "Kongkong.Text.GenericStaticString.h"

namespace klib::Kongkong
{
	/// <summary>
	/// メモリ確保時のエラー
	/// </summary>
	struct MemoryAllocationException : public Exception {
	private:

		Text::StaticString s_outOfMemoryMessage;
		
	public:
		/// <summary>
		/// メモリ不足
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] static MemoryAllocationException OutOfMemory() noexcept;

		using Exception::Exception;
	};
}

#endif //!IMPL_KONGKONG_MEMORYALLOCATIONEXCEPTION_H