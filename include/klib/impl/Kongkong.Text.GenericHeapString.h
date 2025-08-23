#ifndef KLIB_KONGKONG_TEXT_HEAPSTRING_H
#define KLIB_KONGKONG_TEXT_HEAPSTRING_H

#include "base.h"
#include "Kongkong.Text.GenericString.h"

namespace klib::Kongkong::Text
{
	template <CChar TChar>
	class GenericHeapString : public GenericString<TChar> {

	};
}

#endif //!KLIB_KONGKONG_TEXT_HEAPSTRING_H