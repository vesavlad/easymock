// Copyright 2016 Vlad Vesa
// Author: hello@vladvesa.ro (Vlad Vesa)

// EasyMock: a tool for mock global function, member function, class static function, virtual member function.
//
// This file contains internal macros, used to create a uniq mocker for every function, even they have same type.

#ifndef EASYMOCK_INTERNAL_MACRO_H_
#define EASYMOCK_INTERNAL_MACRO_H_

#include "impl.h"

#define MOCKER_INTERNAL(function, identity) \
    ::EasyMock::MockerCreator::GetMocker<::EasyMock::TypeForUniqMocker<identity>>(function, (void*)(function), #function)

#endif // EASYMOCK_INTERNAL_MACRO_H_
