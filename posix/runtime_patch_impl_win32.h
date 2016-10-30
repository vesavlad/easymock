// Copyright 2014 Louix Gu
// Author: gzc9047@gmail.com (Louix Gu)

// CppFreeMock: a tool for mock global function, member function, class static function.
//
// Implement CppFreeMock::RuntimePatcherImpl::UnprotectMemory in win32.

#ifndef CPP_FREE_MOCK_POSIX_RUNTIME_PATCH_IMPL_H_
#define CPP_FREE_MOCK_POSIX_RUNTIME_PATCH_IMPL_H_

#include <cerrno>

#include <unistd.h>

namespace CppFreeMock {

    namespace RuntimePatcherImpl {
        // To be simple, I don't create .cpp for this static value, so you can't include this file in 2 or more cpp file.

        // return 0 for success, otherwire for error.
        static int UnprotectMemory(const void* const address, const size_t length) {
            (void)address;
            (void)length;
            return 0;
        }

        // return 0 for success, otherwire for error.
        static int UnprotectMemoryForOnePage(void* const address) {
            (void) address;
            return 0;
        }
    }

} // namespace CppFreeMock

#endif // CPP_FREE_MOCK_POSIX_RUNTIME_PATCH_IMPL_H_
