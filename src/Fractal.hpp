#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Thread.hpp>

#include <vector>
#include <memory>

namespace sf
{
    class RenderTarget;
}

class Fractal : public sf::Drawable
{
public:
    Fractal(const sf::Vector2u& size, const unsigned int threads = 3);

    void update(const sf::Vector2i& first, const sf::Vector2i& second);

    void resize(const sf::Vector2u& size, const unsigned int threads = 3);
    void precision(const long double& precision);
    const long double& precision();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setThreads(const unsigned int threads);
    sf::Uint8 color(const unsigned int c, const long double z, const sf::Uint8 X, const sf::Uint8 sX, const int sign) const;
    void generate(sf::Rect<unsigned int> section);

private:
    std::vector<std::unique_ptr<sf::Thread>> m_threads;

    // Drawing
    std::vector<sf::Uint8> m_pixels;
    sf::Texture m_texture;
    sf::Sprite m_fractal;

    // Parameters
    sf::Vector3<long double> m_pos;
    float m_pfact;
    long double m_precision;
    sf::Color m_X;
    sf::Color m_sX;
};