export int task_dummy() {
    while (true) {
    }
}

export int task_counter() {
    int *ssegs = (int*) 0xA0000000;
    int counter = 0;
    int i;
    *(ssegs + 1) = 0b1111;
    while (true) {
        *ssegs = counter;
        for(i = 0; i < 10000; i=i+1)
        {
        }
        counter = counter + 1;
    }
}

#include "shell.moc"

export int task_shell() {
    while (true) {
        char* line = getline();
        shell(line);
        free((void*)line);
    }
}

export int task_leds() {
    int *leds = (int*) 0xB0000000;
    int *switches = (int*) 0x90000000;
    while (true) {
        *leds = *switches;
    }
}
