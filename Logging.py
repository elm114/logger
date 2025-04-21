from loguru import logger

# Optional: configure log file (rotates daily)
logger.add("app.log", rotation="1 day", level="DEBUG")

def divide(a, b):
    logger.debug(f"Called divide(a={a}, b={b})")
    try:
        result = a / b
        logger.info(f"Division successful: {result}")
        return result
    except ZeroDivisionError:
        logger.error("Cannot divide by zero", exc_info=True)
        return None
    except Exception as e:
        logger.error(f"Unexpected error: {e}", exc_info=True)
        return None

def main():
    logger.info("App started")

    divide(10, 2)
    divide(10, 0)
    divide("10", 2)  # Intentional error

    logger.info("App finished")

if __name__ == "__main__":
    main()
