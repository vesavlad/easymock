EasyMock, based on CppFreeMock
===========

Forked from [cppfreemock](https://github.com/gzc9047/CppFreeMock), based on gmock, can mock global function, member (virtual/nonvirtual) function, class static function without change source code.

What you have to do:
- include ```easymock.h``` into you test source file
- if using googlemock please make sure that you have included the easymock.h after ```#include<gmock/gmock.h>```
- create a mocker to a desired function using ```CREATE_MOCKER(&...)``` macro
- on the created mocker do a expect call using gmock ```EXPECT_CALL(...)``` macro
- after calling method or function under test make sure that you've cleared the mocker created using ```DISABLE_MOCKER(mocker)``` or ```CLEAR_MOCKER(mocker)```

Hello world *example*:

```cpp
string func() {
    return "Non mocked.";
}

TEST(HelloWorld, First) {
    EXPECT_CALL(*CREATE_MOCKER(func), MOCK_FUNCTION()).Times(Exactly(1)).WillOnce(Return("Hello world."));
    EXPECT_EQ("Hello world.", func());
}
```
