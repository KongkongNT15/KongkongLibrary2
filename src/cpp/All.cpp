#include "All.h"

#include <ostream>

#include "impl/Kongkong.GC.cpp"
#include "impl/Kongkong.InvalidCastException.cpp"
#include "impl/Kongkong.Object.cpp"

#include "impl/Kongkong.Text.GenericFastString.cpp"
#include "impl/Kongkong.Text.GenericFastStringBase.cpp"
#include "impl/Kongkong.Text.GenericHeapString.cpp"
#include "impl/Kongkong.Text.GenericStaticString.cpp"
#include "impl/Kongkong.Text.GenericString.cpp"
#include "impl/Kongkong.Text.GenericStringMemory.cpp"

#include "impl/Kongkong.Threading.Mutex.cpp"

#if KLIB_ENV_WINDOWS
#include "impl/Kongkong.Win32.Handle.cpp"
#endif