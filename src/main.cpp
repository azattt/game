#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class TextureManager
{
  public:
    TextureManager(const std::string textures_path) : textures_path(textures_path)
    {
        sf::Texture error_texture = load_texture("error.png");
        error_texture.setRepeated(true);
    }

    TextureManager() = delete;

    sf::Texture &load_texture(const std::string texture_path)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(textures_path + texture_path))
        {
            constexpr int ERROR_TEXTURE_INDEX = 0;
            return textures[ERROR_TEXTURE_INDEX];
        }
        textures.push_back(texture);
        return textures.back();
    }

  private:
    std::vector<sf::Texture> textures;
    std::string textures_path;
};

struct Vec2f
{
    float x, y;
};

struct CollisionBox
{
    Vec2f top_left;
    Vec2f bottom_right;
};

class Collision
{
  public:
    Collision()
    {
        collision_boxes.push_back({186.0f, 371.0f, 400.0f, 530.0f});
        collision_boxes.push_back({568.0f, 372.0f, 682.0f, 597.0f});
        collision_boxes.push_back({235.0f, 347.0f, 262.0f, 371.0f});
    }
    bool can_move(float x, float y, float dx, float dy)
    {
        float player_width = 16.0f;
        float player_height = 25.0f;
        for (const CollisionBox &box : collision_boxes)
        {
            if (x + dx + player_width >= box.top_left.x && y + dy + player_height >= box.top_left.y &&
                x + dx <= box.bottom_right.x && y + dy <= box.bottom_right.y)
            {
                return false;
            }
        }
        if (x + dx < 0.0f || y + dy < 0.0f || x + dx > 800.0f || y + dy > 800.0f)
        {
            return false;
        }
        return true;
    }
    void draw(sf::RenderWindow &window)
    {
        sf::VertexArray triangle(sf::Triangles, collision_boxes.size() * 6);
        int i = 0;
        for (const CollisionBox &box : collision_boxes)
        {
            // 0    5 4
            // 1 2    3
            triangle[i * 6 + 0].position = sf::Vector2f(box.top_left.x, box.top_left.y);
            triangle[i * 6 + 0].color = {0, 255, 0, 130};
            triangle[i * 6 + 1].position = sf::Vector2f(box.top_left.x, box.bottom_right.y);
            triangle[i * 6 + 1].color = {0, 255, 0, 130};
            triangle[i * 6 + 2].position = sf::Vector2f(box.bottom_right.x, box.bottom_right.y);
            triangle[i * 6 + 2].color = {0, 255, 0, 130};
            triangle[i * 6 + 3].position = sf::Vector2f(box.bottom_right.x, box.bottom_right.y);
            triangle[i * 6 + 3].color = {255, 255, 0, 130};
            triangle[i * 6 + 4].position = sf::Vector2f(box.bottom_right.x, box.top_left.y);
            triangle[i * 6 + 4].color = {255, 255, 0, 130};
            triangle[i * 6 + 5].position = sf::Vector2f(box.top_left.x, box.top_left.y);
            triangle[i * 6 + 5].color = {255, 255, 0, 130};
            i++;
        }
        window.draw(triangle);
    }

  private:
    std::vector<CollisionBox> collision_boxes;
};

unsigned char* load_image(std::string path,)


struct Texture
{
    unsigned char* image;
    int width;
    int height;
    int channels;
};
int main()
{
    std::vector<unsigned char*> images;
    int width, height, channels;
    unsigned char* image = stbi_load("./resources/minetcraft/grass_block_top.png", &width, &height, &channels, 4);
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            image[(y*width + x)*4] *= 0.52;
            image[(y*width + x)*4+1] *= 0.67;
            image[(y*width + x)*4+2] *= 0.41;
            image[(y*width + x)*4+3] = 255;
        }
    }
    sf::Texture grass_texture;
    grass_texture.create(width, height);
    grass_texture.update(image);
    sf::Sprite sprite(grass_texture);
    // sprite.setScale(sf::Vector2f(10.0f, 10.0f));
    int** grid = new int*[100];
    for (int i = 0; i < 100; i++){
        grid[i] = new int[100];
        for (int j = 0; j < 100; j++){
            grid[i][j] =
        }
    }

    Vec2f player_position{400.0f, 300.0f};

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
}