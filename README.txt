# SFML 2 Running Text Example
Example how to create running text with SFML 2.x using Codeblocks IDE on Windows environment.

1. Install Codeblocks & SFML
   -------------------------
   Download and install Codeblocks:
   http://prdownload.berlios.de/codeblocks/codeblocks-13.12mingw-setup-TDM-GCC-481.exe
   Install into your local driver like this 'C:\CodeBlocks'.
   Select 'GNU GCC Compiler' as your default compiler.
   -------------------------
   Download and install SFML:
   http://www.sfml-dev.org/files/SFML-2.2-windows-gcc-4.8.1-tdm-32-bit.zip
   Unzip into Codeblocks folder, something like this 'C:\CodeBlocks\SFML-2.2'.

2. Create new SFML project:
   ------------------------
   From Codeblocks IDE, click 'Create New Project'.
   From pop-up window, scroll down and select 'SFML Project' and click 'GO'.
   Click 'Next', select 'SFML 2.0' and click 'Next'.
   Select 'Dynamic Link Library' and click 'Next'.
   ------------------------
   Keyin 'Project Title:' , example 'RunText'
   Browse where you want to locate your project,
   'Folder to create project in:'
   Click 'Next'
   ------------------------
   Please select SFML's location:
   C:\CodeBlocks\SFML-2.2
   Click 'Next'.
   Click 'Finish'.

3. Setup Project Configuration:
   ----------------------------
   We are going to run our project in 'Release' mode.
   ----------------------------
   Change build target to 'Release'.
     'Build' -> 'Select Target' -> 'Release'
   Change project properties 'Release' mode 'Execution working dir:' from '.' to 'bin\Release\'.
     'Project' -> 'Properties...'
   ----------------------------
   From pop-up window:
   Click tab 'Build Targets'
   From panel 'Build Target'
   Click on 'Release' item.
   Change 'Execution working dir:' from '.' to 'bin\Release\'.
   Click 'OK'.

4. Test Your Project:
   ------------------
   Build the project.
     'Build' -> 'Build' or press 'Ctrl+F9'.
   Execution file, 'RunText.exe' will be generated inside 'Release' folder.
     ../bin/Release/RunText.exe
   ------------------
   Before run the execute file, for the first time you have to do this:
   ------------------
   Copy following dll files into your execution folder.
   'C:\CodeBlocks\MinGW\bin\libgcc_s_sjlj-1.dll'
   'C:\CodeBlocks\MinGW\bin\libdc++-6.dll'
   'C:\CodeBlocks\MinGW\SFML-2.2\bin\sfml-graphics-2.dll'
   'C:\CodeBlocks\MinGW\SFML-2.2\bin\sfml-system-2.dll'
   'C:\CodeBlocks\MinGW\SFML-2.2\bin\sfml-window-2.dll'
   ----
   Copy project default bitmap file 'cb.bmp' from project source folder into '../bin/Release' folder.
   move '../your_project_folder/cb.bmp' into  '../your_project_folder/bin/Release/cb.bmp'
   ------------------
   Test execution program:
     'Build' -> 'Run' or 'Ctrl+F10' or double-click on 'RunText.exe'.

5. Change Your Code for Running Text:
   ----------------------------------
   Download font file 'arial.ttf' into '../bin/Release' folder.
   ----------------------------------
   Your original code:
   
     #include <SFML/Graphics.hpp>

     int main()
     {
         // Create the main window
         sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

         // Load a sprite to display
         sf::Texture texture;
         if (!texture.loadFromFile("cb.bmp"))
             return EXIT_FAILURE;
         sf::Sprite sprite(texture);

	     // Start the game loop
         while (app.isOpen())
         {
           :
           :

   Change to this code:
   
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

