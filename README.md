# SFML-Data-Structures-Project

ADT Visualizer

This project is a command-line interface (CLI) and graphical user interface (GUI)-based program to visualize Abstract Data Types (ADTs) such as Binary Search Trees (BSTs), Heaps, AVL Trees, and B-Trees.

How It Works

1. Launching the Program

Run the program from the terminal. A CLI menu will appear, prompting you to select an ADT to work with.

2. Selecting an ADT

Choose from the following options:

1: Binary Search Tree

2: Heap

3: AVL Tree

4: B-Tree

5: Exit

3. Performing Operations

After selecting an ADT, you can:

Insert: Add a value to the ADT.

Find: Check if a value exists in the ADT (not implemented yet).

Delete: Remove a value from the ADT (not implemented yet).

Visualize: Open a GUI window to see the current state of the selected ADT.

4. Visualization

The visualization window:

Opens when you select "Visualize" from the CLI.

Displays the structure and elements of the current ADT.

Uses ArialMdm.ttf for rendering text. Ensure this font file is in the same directory as the executable.

5. Returning to the Main Menu

From the operations menu, you can choose Back to Main Menu to select a different ADT.

Prerequisites

SFML Library: Install SFML for graphical rendering.

C++ Compiler: Ensure your compiler supports modern C++ (e.g., GCC 9+ or Clang).

Compilation

Compile the program using the following command:

g++ introLab.cpp BST.cpp Heap.cpp AVL.cpp BTree.cpp -o ADTVisualizer -lsfml-graphics -lsfml-window -lsfml-system

File Structure

introLab.cpp: Main program with CLI and GUI logic.

BST.h / BST.cpp: Binary Search Tree implementation.

Heap.h / Heap.cpp: Heap implementation.

AVL.h / AVL.cpp: AVL Tree implementation.

BTree.h / BTree.cpp: B-Tree implementation.

ArialMdm.ttf: Font file for GUI text rendering.

Known Issues

Find and Delete: These functionalities are placeholders and not yet implemented.

Ensure ArialMdm.ttf is in the correct directory to avoid font loading errors.

Future Improvements

Implement Find and Delete operations.

Add more ADTs like Red-Black Trees.

Enhance GUI interactivity.

Usage Example

Start the program.

Select "1" for Binary Search Tree.

Insert values like "10" and "20."

Visualize the BST to see the structure.

Return to the main menu and select another ADT.

Author

Christian Johnson, Software Engineering Major, Morehouse College.

