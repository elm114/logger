        if (!isValidMessage(message)) {
            throw LoggerException("Logging message must be non-empty and non-whitespace.");
        }