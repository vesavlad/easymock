// Copyright 2016 Vlad Vesa
// Author: hello@vladvesa.ro (Vlad Vesa)

// EasyMock: a tool for mock global function, member function, class static function, virtual member function.
//
// Implement EasyMock::RuntimePatcherImpl::UnprotectMemory in win32.

#ifndef EASYMOCK_POSIX_RUNTIME_PATCH_IMPL_WIN32_H_
#define EASYMOCK_POSIX_RUNTIME_PATCH_IMPL_WIN32_H_

#include <windows.h>

#define protREAD  1
#define protWRITE 2
#define protEXEC  4

extern "C" {
    int mprotect(void *addr, size_t len, int prot) {
        DWORD wprot = 0;
        if (prot & protWRITE) {
            wprot = PAGE_READWRITE;
        } else if (prot & protREAD) {
            wprot = PAGE_READONLY;
        }

        if (prot & protEXEC) {
            wprot <<= 4;
        }

        DWORD oldwprot;
        if (!VirtualProtect(addr, len, wprot, &oldwprot)) {
            return -1;
        }

        return 0;

    }



} // extern "C"

#include <iostream>
#include <cerrno>
#include <unistd.h>


namespace EasyMock {
    namespace RuntimePatcherImpl {
        // To be simple, I don't create .cpp for this static value, so you can't include this file in 2 or more cpp file.

        // return 0 for success, otherwire for error.
        static int UnprotectMemory(const void* const address, const size_t length) {
            SYSTEM_INFO systemInfo;
            GetSystemInfo(&systemInfo);
            // Here we assume that page size is power of 2.
            void* const page = reinterpret_cast<void*>(AlignAddress(reinterpret_cast<std::size_t>(address), systemInfo.dwPageSize));
            int ret = mprotect(page, length, protREAD | protWRITE | protEXEC);
            if (ret != 0) {
                int err = errno;
                std::cerr << "Unprotect memory: " << address
                          << " meet errno: " << err
                          << " description: " << strerror(err) << std::endl;
            }
            return ret;
        }

        // return 0 for success, otherwire for error.
        // return 0 for success, otherwire for error.
        static int UnprotectMemoryForOnePage(void* const address) {
            SYSTEM_INFO systemInfo;
            GetSystemInfo(&systemInfo);
            return UnprotectMemory(address, systemInfo.dwPageSize);
        }
    }

} // namespace EasyMock

#endif // EASYMOCK_POSIX_RUNTIME_PATCH_IMPL_WIN32_H_
