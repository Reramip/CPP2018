#pragma once

class Food {
    int x;
    int y;
public:
    Food();
    void create();
    void show();
    friend class Snake;
};
