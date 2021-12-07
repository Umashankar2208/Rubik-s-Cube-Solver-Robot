import pycuber as pc
from pycuber.solver import CFOPSolver
import time

# convert numbers to letters
def convert_num(cube):
    
    cube = cube.replace('r', '0')
    cube = cube.replace('y', '1')
    cube = cube.replace('g', '2')
    cube = cube.replace('w', '3')
    cube = cube.replace('o', '4')
    cube = cube.replace('b', '5')   
    return cube

#convert alphabets to appropriate numbers
def convert_letter(cube):
    cube = cube.replace('0', 'g')
    cube = cube.replace('1', 'r')
    cube = cube.replace('2', 'y')
    cube = cube.replace('3', 'w')
    cube = cube.replace('4', 'b')
    cube = cube.replace('5', 'o')   
    return cube

# convert into cube like form
def convert_pycube(cube):
    cube = pc.Cube(pc.array_to_cubies(cube))
    return cube

# solve the cube and get the solution sequence
def find_sol(cube1):
    solver = CFOPSolver(cube1)  
    sol = solver.solve()
    return sol

# read the color code from text file
f = open("C://Users//umash//Downloads//color_codes.txt", "r")  # change location according to your directory
cube_state = str(f.read())

cube1 = cube_state
cube2 = cube_state

cube1 = convert_letter(cube1)
cube2 = convert_letter(cube2)

cube1 = convert_num(cube1)
cube2 = convert_num(cube2)

cube1 = convert_pycube(cube1)
cube2 = convert_pycube(cube2)

try:
    sol = find_sol(cube1)
except:
    print("Invalid Cube")
    exit(0)


#replace letters with full line command
sol_seq = []
com_item = []
for i in sol:
    sol_seq.append(str(i))


print("Number of Steps : "+str(len(sol_seq)))


for item in sol_seq:
    if item == 'F':
        com_item.append(str("front clock")) 

    if item == 'F2':
        com_item.append(str("front clock twice")) 

    if item == "F'":
        com_item.append(str("front anticlock")) 

    if item == "F2'":
        com_item.append(str("front anticlock twice")) 

    if item == 'L':
        com_item.append(str("left up")) 

    if item == 'L2':
        com_item.append(str("left up twice"))
    
    if item == "L'":
        com_item.append(str("left down")) 
    
    if item == "L2'":
        com_item.append(str("left down twice"))

    if item == 'B':
        com_item.append(str("back clock")) 

    if item == 'B2':
        com_item.append(str("back clock twice"))

    if item == "B'":
        com_item.append(str("back anticlock")) 

    if item == "B2'":
        com_item.append(str("back anticlock twice"))

    if item == 'R':
        com_item.append(str("right up"))

    if item == 'R2':
        com_item.append(str("right up twice"))
    
    if item == "R'":
        com_item.append(str("right down"))

    if item == "R2'":
        com_item.append(str("right down twice"))

    if item == 'U':
        com_item.append(str("up clock")) 

    if item == 'U2':
        com_item.append(str("up clock twice"))

    if item == "U'":
        com_item.append(str("up anticlock"))

    if item == "U2'":
        com_item.append(str("up anticlock twice"))

    if item == 'D':
        com_item.append(str("down clock"))

    if item == 'D2':
        com_item.append(str("down clock twice"))
    
    if item == "D'":
        com_item.append(str("down anticlock"))

    if item == "D2'":
        com_item.append(str("down anticlock twice"))


import serial
print("\nCONNECTING TO ARDUINO....")
time.sleep(2)
arduino = serial.Serial("COM3",9600)
time.sleep(2)
print("\n\nCONNECTED")

def pos(com):
    arduino.write(com.encode())

print("\n")
time.sleep(1)
for i in range(5):
    com = str(input("\nENTER COMMAND: "))
    pos(com)

print("\n")
print("STARTED...!")
time.sleep(1)
j=0
for i in com_item:
    j+=1
    cube2.perform_algo(str(sol_seq[j]))
    print(repr(cube2))
    com = str(i)
    print("\nExecuting : "+str(i))
    pos(com)
    if i == "up clock" or i == "up clock twice" or i == "up anticlock" or i == "up anticlock twice" or i == "down clock" or i == "down clock twice" or i == "down anticlock" or i == "down anticlock twice" :
        time.sleep(1)
        pass
    time.sleep(1)
end = time.time()

print("\n\n CUBE SOLVED")
time.sleep(2)
