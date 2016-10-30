// Copyright 2016 Vlad Vesa
// Author: hello@vladvesa.ro (Vlad Vesa)

// EasyMock: a tool for mock global function, member function, class static function, virtual member function.
//
// This file contains user level macro.
// User can only use the symbols in this file.

#ifndef EASY_MOCK_H_
#define EASY_MOCK_H_
#include <assert.h>
#include "impl.h"

// mocker is the variable name in user code.
// Used to create:
//  1, global function;
//  2, static member function;
//  3, member function mocker that can check this pointer.
//  4, virtual member function mocker that can check this pointer.
#define CREATE_MOCKER(function) ::CppFreeMock::MockerCreator::GetMocker<::CppFreeMock::TypeForUniqMocker<__COUNTER__>>(function, reinterpret_cast<void*>(function), #function)
#define DISABLE_MOCKER(mocker) assert(mocker!=nullptr); mocker->disable()
#define ENABLE_MOCKER(mocker) assert(mocker!=nullptr); mocker->enable()
#define CLEAR_MOCKER(mocker) assert(mocker!=nullptr); mocker->disable()
#define CLEAR_MOCKERS ::CppFreeMock::MockerCreator::RestoreAllMockerFunctionToReal

// Used in EXPECT_CALL(*mocker, MOCK_FUNCTION(_))
#define MOCK_FUNCTION CppFreeMockStubFunction

#endif // EASY_MOCK_H_
