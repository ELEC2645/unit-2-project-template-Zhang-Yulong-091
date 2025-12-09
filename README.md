# ELEC2645 Unit 2 Project Template
The project is a console-based program written in C that provides a six-option main menu. Each main option leads to a dedicated sub-menu with specific mathematical or computational operations. All sub-menus end with an Exit option that returns to the main menu. The six main options are:

Linear algebra library
Basic statistical tools
Simple electrical circuit
Simple calculator
Query Assistant 
Exit (terminate the program)
Each of the first four options opens a corresponding sub-menu. All sub-menus include Exit to return to the Main Menu.

1.Linear algebra library
Sub-menu items:
Matrix addition
Matrix subtraction
Matrix multiplication
Determinant
Exit (return to Main Menu)
Operations assume standard matrix inputs (dimension checks required). Determinant is defined for square matrices only.

2.Basic statistical tools
First, ask: "How many data points?"
Then sub-menu:
Mean
Median
Variance
Standard deviation
Exit (return to Main Menu)

3.Simple electrical circuit
Sub-menu:
Calculate resistance (R) given voltage (V) and current (I): R = V / I
Calculate voltage (V) given resistance (R) and current (I): V = I * R
Calculate current (I) given voltage (V) and resistance (R): I = V / R
Calculate total resistance: ask for number of resistors, then choose series or parallel, then sum appropriately
Exit (return to Main Menu)

4.Simple calculator
Sub-menu:
Simple data calculation (evaluate arithmetic expressions)
Graphical information calculation
Further submenu: circle, square, rectangle, sector
For each shape, input the required parameters (e.g., circle: radius; square: side; rectangle: length and width; sector: radius and angle)
Output: area and perimeter (or relevant metrics)
Exit (return to Main Menu)

5.Query Assistant 
Concept: A lightweight, guidance-oriented helper that, once selected, provides high-level options mapping back to the four main functional modules:
Matrix operations (Linear algebra library)
Data values (Basic statistical tools)
Electrical quantities (Simple electrical circuit)
Calculations and shape metrics (Simple calculator)
It prints the relevant main-menu information to guide the user.

6.Exit 
Exit terminates the program.