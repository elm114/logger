#include <iostream>
#include <string>


enum LoggingLevel {
    INFO = 0,
    DEBUG = 1,
    ERROR = 2
};

class LoggerException : public std::exception{

private:

    std::string Message;

public:
    
     explicit LoggerException(const std::string& msg) : Message("Logger ERROR: " + msg) {}


     const char* what() const noexcept override {
        return Message.c_str();
     }

};

class ConsoleLogger {
public:
    void print(LoggingLevel level, const std::string& message) const {
        if (!isValidMessage(message)) {
            throw LoggerException("Logging message must be non-empty and non-whitespace.");
        }

        std::cout << "[" << getLogLevelString(level) << "] " << message << std::endl;
    }

private:
    std::string getLogLevelString(LoggingLevel level) const {

//    switch(level){

//    case 0: return "INFO";
//     break;

//    case 1: return "DEBUG";
//     break;

//    case 2: return "ERROR";
//     break;
    
//     default:
//         return "UNKNOWN";

//     }
   

        if (level == 0){
            return "INFO";
        }
        else if (level == 1){
            return "DEBUG";
        }
        else if (level == 2) {
            return "ERROR";
        }
        else {
            return "UNKOWN";
        }
        
    }
    bool isValidMessage(const std::string& message) const {
        return !message.empty() && message.find_first_not_of(" \t\n\r") != std::string::npos;
    }
};

class Application {
private:
    ConsoleLogger logger;

public:

    void run() { try {
        logger.print(LoggingLevel::INFO, "Application is starting...");
        logger.print(LoggingLevel::DEBUG, "Low memory debuging...");
        logger.print(LoggingLevel::ERROR, "Critical error encountered!");
        logger.print(LoggingLevel::INFO, "");
    }

    catch (const LoggerException& e) {
        std::cerr << e.what() << std::endl;
    }
}
};

int main() {

    Application* app = new Application();
    app->run();
    delete app;
    app = nullptr;
    
    
}
