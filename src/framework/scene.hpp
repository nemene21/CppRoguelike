#ifndef SCENE_H
#define SCENE_H

#include <entity.hpp>
#include <vector>

#include <test_entity.hpp>
#include <tilemap_entity.hpp>
#include <misc.hpp>

class Scene {
public:
    std::string name;

    Scene(std::string name);

    virtual void process(float delta);

    virtual void draw_entities(float delta);
    virtual void process_entities(float delta);

    virtual void restart() = 0;

protected:
    std::vector<Entity*> entities;
};

class Tilemap;

class TestScene: public Scene {
public:
    TestScene();
    void restart();

    Tilemap *tiles;
};

typedef std::map<std::string, Scene*> SceneMap;
class SceneManager {
public:
    static SceneMap scene_map;
    static Scene* scene_on;

    static void setup_scene(Scene* scene);
    static void unload(std::string name);
    static void unload_all();

    static void set_scene(std::string name);
};

#endif