# 3081 Lab 2: Classes and Compiling
_(Due: Thursday, September. 22, 2022 @ 11:59pm)_

## What You Will Learn

1. What is class.
2. When to use class.
3. How to create and use class.
4. How to use makefiles.

## General Information

### Accesing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)). You can access a lab machine also remotely using [VOLE](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/VOLE) and [SSH](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/SSH).

**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/kaung006`) will be persisted across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

### Diskquota Exceed
One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. <br>
To free up space, [see here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/CSE%20Disk%20Quota%20Exceeds)

## Retrieve Class Materials

1. Clone **public lab02** repo
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/public-lab02.git
    ```

2. Clone your **private lab02** repo<br>
    *Note: **replace** x500 with your x500*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/x500-lab02.git
    ```

3. Copy the content of **public lab02** repo into your **private lab02** repo and you can start working inside your private repo.

### What's in lab02 folder?

- main.cc:
  - This contains the main function, which creates and operates on ducks information.

- Makefile:
  - This makefile is provided to allow you to easily build the executable to run this program. Initially it will only compile and build main.cc, you will have to build this up to support new files (Duck.cc and Duck.h)

- README.md:
    - You're reading this now.

### What You Will Add

- Duck.cc:
  - The source file for the duck class definition.

- Duck.h ([see example](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/blob/main/Examples/Name/Name.h)):
    - The header file for this new duck class. It should include the declaration of three constructors and the six class methods: 
        - Constructors 
        - print_all
        - get_color
        - get_type
        - get_name
        - get_mother
        - give_birth
    - If you are not familiar with header file guards, you can go to the Zybook section 6.18 for reference: [Zybook section link](https://learn.zybooks.com/zybook/UMNCSCI3081WFall2022/chapter/6/section/18)

- Makefile (modify):
    - Compilition and build codes to support Duck.cc and Duck.h

## Lab Instructions
### Part 1 (Create Duck class)
You have heard of what and why to use the classes during the lecture, so now you will be implenting it to create Duck class. <br>
You will be creating 2 new files called `Duck.cc` and `Duck.h` <br>
`Duck.cc` will consist of the actual class function implementations and `Duck.h` will consist of function declarations and macro definitions to be shared between several source files.

`Duck.h`
1. Create header guards
2. Create Duck class with
   - 3 constructors
     - Default constructor
     - Constructor with parameters
       - name: string
       - type: string
       - color: string
     - Constructor with parameters
       - name: string
       - type: string
       - color: string
       - mother: Duck*
   - 6 functions
     - give_birth( )
       - parameter - name: string
       - returns: Duck*
     - get_name( )
       - returns: string
     - get_type( )
       - returns: string
     - get_color( )
       - returns: string
     - get_mother( )
       - returns: Duck*
     - print_all( )
   - 4 private variables
     - name: string
     - type: string
     - color: string
     - mother: Duck*

  Example:<br>
  ```
  class Chicken {
    public:
      Chicken();
      .
      .
      .
    private:
      .
      .
      .
  }
  ```
  
`Duck.cc`
1. Include your `Duck.h` file here
2. To declare the functions or constructor from header class:<br>
    Example:<br>
    *Note: **First** chicken is the class name, **Second** chicken is the function or constructor title*
    ```
    Chicken::Chicken() {
      .
      .
      .
    }
    ```
3. Implement the actual functions that was declared inside the `Duck.h`
   - Default constructor
     - Assign private variable name, type, and color to "Unknown"
     - Assign private variable mother to NULL
   - Constructor with only name, type and color
     - Assign the name, type and color accordingly using the given parameters
     - Assign private variable mother to NULL
   - Constructor with name, type, color and mother
     - Assign the name, type, color and mother accordingly using the given parameters
   - give_birth()
     - create new Duck with name from the parameter, type of current duck type, color of current duck color, and mother as current duck
   - get_name()
     - return current duck name
   - get_type()
     - return current duck type
   - get_color()
     - return current duck color
   - get_mother()
     - return current duck's mother
   - print_all()
     - copy and paste the code below
     ```
      std::cout << "Name: " << name << std::endl;
      std::cout << "Type: " << type << std::endl;
      std::cout << "Color: " << color << std::endl;
      if(mother){
        std::cout << "Mother's Name: " << mother->get_name() << std::endl;
        std::cout << "Mother's Type: " << mother->get_type() << std::endl;
        std::cout << "Mother's Color: " << mother->get_color() << std::endl;
      } else {
        std::cout << "Mother: Unknown" << std::endl;
      }
        std::cout << "-------------------------" << std::endl;
     ```

If you have implemented both `Duck.cc` and `Duck.h` files correctly, then inside the `main.cc`, uncomment the function useObject() and some codes inside the main function.

*Note: you would also have to include the `Duck.h` file inside the `main.cc` similar to the one you include inside the `Duck.cc`*

### Part 2
1. Locate to your repo
2. Inside the Makefile, replace
```
run: main.o
	$(CXX) $(CXXFLAGS) main.o -o run 
```
with 
```
run: main.o Duck.o	
	$(CXX) $(CXXFLAGS) main.o Duck.o -o run
```
3. Open terminal
4. Copy the command below to create executable file
   ```
   make
   ```
5. Run the command below to run the program
   ```
   ./run
   ```
6. Compare your output from your terminal with the output below
   ```
    CSCI3081W Lab 2 - Classes
    =========================
    Display using vector
    =========================
    Name: Unknown
    Type: Unknown
    Color: Unknown
    -------------------------
    Name: King
    Type: Canvasback
    Color: brown-white
    -------------------------
    Name: Mob
    Type: Mallard
    Color: green-white
    -------------------------

    =========================
    Display using object class
    =========================
    Name: Unknown
    Type: Unknown
    Color: Unknown
    Mother: Unknown
    -------------------------
    Name: King
    Type: Canvasback
    Color: brown-white
    Mother: Unknown
    -------------------------
    Name: Mob
    Type: Mallard
    Color: green-white
    Mother's Name: Whity
    Mother's Type: Mallard
    Mother's Color: green-white
    -------------------------
    Name: White
    Type: Mallard
    Color: green-white
    Mother's Name: Whity
    Mother's Type: Mallard
    Mother's Color: green-white
    -------------------------
   ``` 
7. If your output matches, then you have completed the lab!.
   
Now you have completed your lab!!!
So push all of your works to github (if you forgot how to push to github, check lab 1 again) and follow the instruction below in the `Final Submission`.

### Final Submission

To submit your assignment, post on the Gradescope assignment "Lab 2: Classes and Makefile" your x500 and the commit ID for your submission.
[Click here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/Commit%20ID) to see how to obtain commit ID.
