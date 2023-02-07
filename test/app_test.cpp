#include <gtest/gtest.h>
#include <string>

#include "../inc/app.h"

testing::AssertionResult AreEqual(const std::string& a, const std::string& b) {
    if (a.compare(b) == 0) {
        return testing::AssertionSuccess();
    } else {
        return testing::AssertionFailure() << a << " and " << b << " are not equal";
    }
}

class AppTest: public ::testing::Test {
    public:
        void SetUp() override {}
        void TearDown() override {}
};

TEST_F(AppTest, TestAppDefaultConstructor) {
    App app1;
    App app2;
    EXPECT_TRUE(AreEqual(app1.getMessage(), app2.getMessage()));
}

TEST_F(AppTest, TestAppGetMessage) {
    App app;
    EXPECT_TRUE(AreEqual("Hello World!", app.getMessage()));
}