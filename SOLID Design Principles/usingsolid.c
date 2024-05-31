/*
   This C code demonstrates the application of SOLID Design Principles, focusing on Interface Segregation and Dependency Injection.
   SOLID principles are a set of guidelines for software development aiming to make software designs more understandable, flexible, and maintainable.

   Here's a breakdown of the code:

   1. Interface Segregation:
      - An interface `Display` is defined to represent a display mechanism.
      - It contains a single function pointer `show` responsible for displaying content.

   2. Dependency Injection:
      - Two concrete implementations are provided:
        a. `consoleShow`: Displays content on the console.
        b. `createConsoleDisplay`: Creates a `Display` object that uses `consoleShow`.
      - The `Application` struct depends on a `Display` object, but it's not coupled to specific display implementation details.
      - `createApplication` initializes an `Application` object with the provided display, allowing different display implementations to be injected.
      - `runApp` utilizes the injected display to show a message.

   Execution Flow:
   - `main` function:
     - Creates a console display using `createConsoleDisplay`.
     - Creates an application using `createApplication`, injecting the console display.
     - Executes the application using `runApp`.
     - Frees allocated memory before returning.

   This design allows for flexibility as different display implementations can be easily swapped without modifying the core application logic. It promotes separation of concerns and improves maintainability.
*/

#include <stdio.h>
#include <stdlib.h>

// Interface for displaying content
typedef struct Display {
    void (*show)(const char*);
} Display;

// Implement a ConsoleDisplay
void consoleShow(const char* message) {
    printf("Console: %s\n", message);
}

// Creates a console display
Display* createConsoleDisplay() {
    Display* display = (Display*)malloc(sizeof(Display));
    if (!display) {
        printf("Memory allocation error\n");
        exit(1);
    }
    display->show = consoleShow;
    return display;
}

// Implement an Application
typedef struct Application {
    Display* display;
} Application;

// Creates an application with the given display
Application* createApplication(Display* display) {
    Application* app = (Application*)malloc(sizeof(Application));
    if (!app) {
        printf("Memory allocation error\n");
        exit(1);
    }
    app->display = display;
    return app;
}

// Executes the application
void runApp(Application* app) {
    app->display->show("Hello, SOLID principles in C!");
}

int main() {
    // Create a console display
    Display* consoleDisplay = createConsoleDisplay();
    // Create an application with the console display
    Application* app = createApplication(consoleDisplay);
    // Run the application
    runApp(app);

    // Clean up
    free(consoleDisplay);
    free(app);

    return 0;
}
