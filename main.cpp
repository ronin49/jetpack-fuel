#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::VertexArray particles(sf::Points, 100);
	for(int i = 0; i < 100; i++) {
		particles[i].position = sf::Vector2f(100+rand()%10-9, 100+rand()%10-9);
		particles[i].color = sf::Color::Yellow;
	}
    sf::VertexArray directions(sf::Points, 100);
	for(int i = 0; i < 100; i++)
		directions[i].position = sf::Vector2f(rand()%2?1:-1, 1);
	window.setFramerateLimit(60);
	sf::Vector2f wind(1,0);
    while (window.isOpen())
    {
		for(int i = 0; i < 100; i++) {
			particles[i].position += directions[i].position;
			if(particles[i].color.g <= 30) {
				particles[i].position = sf::Vector2f(100+rand()%10-9, 100+rand()%10-9);
				directions[i].position = sf::Vector2f(20.0/1000*(rand()%1000)-10, 10);
				particles[i].color.g = 255;
			} else
			particles[i].color.g-=30;
		}
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(particles);
        window.display();
    }

    return 0;
}