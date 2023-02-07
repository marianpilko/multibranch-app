#ifndef APP_H
#define APP_H

#include <string>

class App {
    private:
        const std::string MESSAGE = "Hello World!";
    public:
        App() = default;
        ~App() = default;
        auto getMessage() noexcept -> std::string;
};

#endif // APP_H