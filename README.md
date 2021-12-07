# Rubik-s-Cube-Solver-Robot
This is the prototype of a robot which is capable of solving a 3*3 Rubik's cube. The robot is made up of Acrylic sheet, with  4 arms to hold and rotate side of the cube.
The project consist of 3 phases, 
1. current state of the cube is fed into the system, manually by the user via Web-UI, file namesd: COLOR_SELECTOR_WEB_UI.html
2. The solving algorithm takes input of the current scrambled state and solves the 3*3 cube in CFOP approach, which returns the solution sequence to be followed by the actuators
3. The solution sequence is fed into the microcontroller (Arduino UNO), and the following sequence of moves is carried out with the help of 8 servo motors.


