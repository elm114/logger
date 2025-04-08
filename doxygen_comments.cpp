#include <iostream>
#include <string>


enum LoggingLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
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


/**
 * This is a simple console logger class.
 * 
 * @author elm114 
 */
class ConsoleLogger {
public:
    /**
     * Prints logging level with logging message.
     *
     * @param level logging level
     * @param message message to print
     * @throws LoggerException If message is empty
     *     
    */                                                                           
    void print(LoggingLevel level, const std::string& message) const {
        if (!isValidMessage(message)) {
            throw LoggerException("Logging message must be non-empty and non-whitespace.");
        }

        std::cout << "[" << getLogLevelString(level) << "] " << message << std::endl;
    }

private:
    std::string getLogLevelString(LoggingLevel level) const {

        if (level == 0){
            return "DEBUG";
        }
        else if (level == 1){
            return "INFO";
        }
        else if (level == 2) {
            return "WARN";
        }
        else if (level == 3){
            return "ERORR";
        }
        else if (level == 4){
            return "FATAL";
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
        logger.print(LoggingLevel::WARN, "WARING! WARING!");
        logger.print(LoggingLevel::FATAL, "it's FATAL");
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
