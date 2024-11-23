#include "engine.h"

bool initialize(Engine* engine) {
    memset(engine, 0, sizeof(Engine));
    if(!window_init(&engine->window, 800, 600, "CPace")) {
        return false;
    }
    render_init(&engine->renderer);

    return true;
}

void shutdown(Engine* engine) {
    fprintf(stdout, "Shutting down Engine...\n");
    renderer_shutdown(&engine->renderer);
    window_shutdown(&engine->window);
    memset(engine, 0, sizeof(Engine));
    fprintf(stdout, "Exit\n");
}

void render(Engine* engine) {
    renderer_draw(&engine->renderer);
    glfwSwapBuffers(engine->window.window);
} 

void update(Engine* engine) {

}

void input(Engine* engine) {
    process_input(&engine->window);
}

void run(Engine* engine) {
    if(!initialize(engine)) {
        LOGERR("Failed to init engine");
    }

    while(!glfwWindowShouldClose(engine->window.window)) {
        input(engine);
        update(engine);
        render(engine);
    }
    shutdown(engine);
}