# cbws
Example how to create running message using SFML 2.x using Codeblocks IDE on Windows environment.

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

   
