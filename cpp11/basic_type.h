// Copyright 2016 Vlad Vesa
// Author: hello@vladvesa.ro (Vlad Vesa)

// EasyMock: a tool for mock global function, member function, class static function, virtual member function.
//
// Basic template type, must be specialization.

#ifndef EASYMOCK_CPP11_BASIC_TYPE_H_
#define EASYMOCK_CPP11_BASIC_TYPE_H_

namespace EasyMock
{

    template < int uniq >
    struct TypeForUniqMocker { };

    template < typename T >
    struct MockerBase { };

    template < typename T >
    struct Mocker : public MockerBase<T> { };

    template < typename T >
    class MockerEntryPoint { };

    template < typename T >
    struct SimpleSingleton {
        static T& getInstance() {
            static T value;
            return value;
        }
    };

} // namespace EasyMock

#endif // EASYMOCK_CPP11_BASIC_TYPE_H_
