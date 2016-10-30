EasyMock
===========

Forked from [cppfreemock](https://github.com/gzc9047/CppFreeMock) Based on gmock, can mock global function, member (virtual/nonvirtual) function, class static function without change source code.


Hello world:

```cpp
string func() {
    return "Non mocked.";
}

TEST(HelloWorld, First) {
    EXPECT_CALL(*CREATE_MOCKER(func), MOCK_FUNCTION()).Times(Exactly(1)).WillOnce(Return("Hello world."));
    EXPECT_EQ("Hello world.", func());
}
```
