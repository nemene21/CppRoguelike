#include <test_entity.hpp>

void track1(Entity *entity) {
    AudioManager::play_track("1.wav", 0.5);
}
 
void track2(Entity *entity) {
    AudioManager::play_track("2.wav", 0.5);
}

void pogger(Entity *entity) {
    std::cout << "Time passed: " << GetTime() << std::endl;
}

TestEntity::TestEntity():
    sprite {Sprite("test.png")},
    particle_sys {ParticleSystem("test.json")},
    track_bool {false}
{
    trail_vfx = Trail({0, 0}, 40, 24, BLUE, {255, 0, 0, 0});
    particle_sys.z_coord = -1;
    trail_vfx.z_coord = -1;

    TransformComponent *transform_comp = new TransformComponent(this);
    transform_comp->position = {500, 0};

    auto *timer_comp = new TimerComponent(this);
    timer_comp->setup();
    test_timer = timer_comp->add_timer("CoolTimer", 5, true);

    test_timer->finished.connect([](Entity *entity) { pogger(entity); });

    sprite.shader_bond = ShaderBond("test.glsl");
    sprite.shader_bond.bind_texture("noise", TextureManager::get("noise.png"));

    add_component( 
        transform_comp
    );

    add_component(
        new HealthComponent(this, 10)
    );
    
    CameraComponent *camera_comp = new CameraComponent(this);
    add_component(
        camera_comp
    );

    ColliderComponent *collider_comp = new ColliderComponent(this, 64, 88);
    collider_comp->set_mask_bit((int)ColliderIndex::TILEMAP, true);

    add_component(
        collider_comp
    );

    AreaComponent *area_component = new AreaComponent(this, 40);
    area_component->set_mask_bit((int)AreaIndex::TEST, true);
    add_component(area_component);

    area_component->area_entered.connect([](Entity *entity) { track1(entity); });
    area_component->area_exited.connect([](Entity *entity) { track2(entity); });

    CameraManager::bind_camera(camera_comp->get_camera());

    particle_sys.set_collision_mask(((TestScene*)SceneManager::scene_on)->tiles);
    particle_sys.add_force({0, 1500});
}

void TestEntity::process(float delta) {
    TransformComponent *transform_comp = (TransformComponent *)get_component(CompType::TRANSFORM);

    particle_sys.process(delta);
    trail_vfx.process(delta);

    float sending = abs(transform_comp->velocity.x / 600.f);
    sprite.shader_bond.send_uniform("jolly", &sending, SHADER_UNIFORM_FLOAT);

    ColliderComponent *collider_comp = (ColliderComponent *)get_component(CompType::COLLIDER);

    transform_comp->interpolate_velocity({
        (float(IsPressed("right")) - float(IsPressed("left"))) * 600.f,
        transform_comp->velocity.y 
    }, 15);

    if (!collider_comp->on_floor())
        transform_comp->accelerate({0, 2500.f * (1.f + 1.5f * (float)(transform_comp->velocity.y > 0))});
    else
        transform_comp->velocity.y = 50;
    
    if (collider_comp->on_ceil()) transform_comp->velocity.y = -.5f * transform_comp->velocity.y;

    CameraComponent *camera = (CameraComponent*)get_component(CompType::CAMERA);
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

        int x = round((GetMousePosition().x + camera->position.x + camera->offset.x - res.x*.5) / 96.0),
            y = round((GetMousePosition().y + camera->position.y + camera->offset.y - res.y*.5) / 96.0);
        ((TestScene *)SceneManager::scene_on)->tiles->set_tile(x, y, 1);

        ((TestScene *)SceneManager::scene_on)->tiles->build();

        test_timer->start();
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {

        int x = round((GetMousePosition().x + camera->position.x + camera->offset.x - res.x*.5) / 96.0),
            y = round((GetMousePosition().y + camera->position.y + camera->offset.y - res.y*.5) / 96.0);
        ((TestScene *)SceneManager::scene_on)->tiles->remove_tile(x, y);

        ((TestScene *)SceneManager::scene_on)->tiles->build();

        test_timer->start();
    }

    sprite.update_transform(transform_comp);
    sprite.scale.x = sprite.scale.x * (int(transform_comp->velocity.x > 0) * 2 - 1);
    sprite.angle = sin(GetTime() * 15) * 10.f * (transform_comp->velocity.x/600.f);

    particle_sys.update_transform(transform_comp);
    particle_sys.angle = Vector2LineAngle({0, 0}, {transform_comp->velocity.x, -transform_comp->velocity.y});
    particle_sys.scale = {sending, abs(transform_comp->velocity.y)/2500.f};
    trail_vfx.update_transform(transform_comp);

    if (IsJustPressed("jump") && collider_comp->on_floor()) {
        transform_comp->velocity.y = -1200;
 
        CameraComponent *camera = (CameraComponent *)get_component(CompType::CAMERA);
        camera->shake(64, 0.25);
        camera->zoom(1.015, 0.15);
        AudioManager::play_sfx("shoot4.mp3", 1, 1, 0, 0.2);

        ParticleEntity *vfx = new ParticleEntity(
            "jump.json",
            transform_comp->position,
            1,
            particle_sys.get_collision_mask()
        );
        vfx->system.add_force({0, 2000});

        SceneManager::scene_on->add_entity(
            (Entity*)vfx
        );
    }
}

void TestEntity::draw(float delta) {
    TransformComponent *transform_comp = (TransformComponent *)get_component(CompType::TRANSFORM);
    DrawLineV(transform_comp->position, mouse_pos(), WHITE);
}