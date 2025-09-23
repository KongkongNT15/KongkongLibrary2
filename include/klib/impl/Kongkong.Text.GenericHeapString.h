#ifndef KLIB_KONGKONG_TEXT_HEAPSTRING_H
#define KLIB_KONGKONG_TEXT_HEAPSTRING_H

#include "base.h"
#include "Kongkong.Text.GenericString.h"
#include "Kongkong.Text.GenericFastString.h"

namespace klib::Kongkong::Text
{
	template <CChar TChar>
	class GenericHeapString : public GenericString<TChar> {
	private:

	public:
	};
}

#endif //!KLIB_KONGKONG_TEXT_HEAPSTRING_H