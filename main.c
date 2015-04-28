/*
 * Written by Hajazi <hajazi@gmail.com>, Apr/28,2015
 */

#include <SFML/Graphics.hpp>

#define BOX_W       150     // width
#define BOX_H       120     // height
#define BOX_XY      10      // speed

#define FOOTER_H    70      // footer height

int main()
{
    // Get screen full size
    sf::VideoMode vm = sf::VideoMode::getDesktopMode();
    int SCR_W = vm.width;
    int SCR_H = vm.height;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(SCR_W, SCR_H), "SFML window", sf::Style::Fullscreen);
    //
    app.setFramerateLimit(50);
    app.setVerticalSyncEnabled(true);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // RunText related items
    sf::Font font1;
    sf::Text textInfo;
    sf::RectangleShape rectInfo;
    //
    if (!font1.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    //
    textInfo.setFont(font1);
    textInfo.setCharacterSize(40);
    textInfo.setColor(sf::Color(255, 255, 255, 255));
    textInfo.setString("WELCOME TO SFML PROGRAMMING. EXAMPLE HOW TO PROGRAM RUNNING MESSAGE, ESC TO EXIT, R:RUN, S:STOP, HOPEFULLY THIS CODE BENEFIT YOU..");
    int TextW = textInfo.getLocalBounds().width;
    //int TextH = textInfo.getLocalBounds().height;
    //
    int InfoX = SCR_W;
    int InfoY = SCR_H - FOOTER_H + 10;
    rectInfo.setSize(sf::Vector2f(SCR_W, FOOTER_H));
    rectInfo.setFillColor(sf::Color(0, 0, 255, 128));
    rectInfo.setPosition(sf::Vector2f(0,SCR_H - FOOTER_H));

    // Animate variables
    int BoxX = SCR_W / 2;
    int BoxY = SCR_H / 2;
    int DirX = BOX_XY;
    int DirY = BOX_XY;
    bool Run = true;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    app.close();
                else if(event.key.code == sf::Keyboard::R)
                    Run = true;
                else if(event.key.code == sf::Keyboard::S)
                    Run = false;
            }
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        if(Run)
        {
            BoxX += DirX;
            BoxY += DirY;
            if(BoxX > (SCR_W - BOX_W))
                DirX = -BOX_XY;
            else if(BoxX < 0)
                DirX = BOX_XY;
            if(BoxY > (SCR_H - BOX_H))
                DirY = -BOX_XY;
            else if(BoxY < 0)
                DirY = BOX_XY;
        }
        sprite.setPosition(sf::Vector2f(BoxX,BoxY));
        app.draw(sprite);

        // Draw message
        InfoX -= 2;
        if(InfoX < -TextW) InfoX = SCR_W;
        textInfo.setPosition(sf::Vector2f(InfoX,InfoY));
        app.draw(rectInfo);
        app.draw(textInfo);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
