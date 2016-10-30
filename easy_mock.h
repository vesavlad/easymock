// Copyright 2014 Vlad Vesa
// Author: hello@vladvesa.ro (Vlad Vesa)

// EasyMock: a tool for mock global function, member function, class static function, virtual member function.
//
// This file contains user level macro.
// User can only use the symbols in this file.

#ifndef EASY_MOCK_H_
#define EASY_MOCK_H_

#include "internal_macro.h"

// mocker is the variable name in user code.
// Used to create:
//  1, global function;
//  2, static member function;
//  3, member function mocker that can check this pointer.
#define MOCKER(function) \
    MOCKER_INTERNAL(function, __COUNTER__)

#define CLEAR_MOCKER ::CppFreeMock::MockerCreator::RestoreAllMockerFunctionToReal

// Used in EXPECT_CALL(*mocker, MOCK_FUNCTION(_))
#define MOCK_FUNCTION CppFreeMockStubFunction

#endif // EASY_MOCK_H_
