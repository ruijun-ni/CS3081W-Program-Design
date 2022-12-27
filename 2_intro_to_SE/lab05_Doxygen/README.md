# 3081 Lab05 - Doxygen
_(Due: Thursday, October. 13, 2022 @ 11:59pm)_

## General Information

### Accesing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)). You can access a lab machine remotely using [VOLE](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/VOLE), FASTX, and [SSH](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/SSH). If you do not already have a CSE account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).

If you are using FASTX, you can access the machine by going to the webpage https://csel-kh1250-XX.cselabs.umn.edu where XX is the machine identifier number, and `kh1250` represents the machine is in the Keller 1-250 lab. In Keller 1-250, the machine numbers are 01-37, and in Keller 1-262 the machine numbers are 01-28. Please do not use the machine in the example below, choose a different one so the entire class isn't trying to work off of the same computer. For example, if you choose to use machine 09 in Keller 1-250, you should type into your web browser [https://csel-kh1250-09.cselabs.umn.edu](https://csel-kh1250-09.cselabs.umn.edu) to connect to your machine. Use your CSE account to login to the machine. One you login, click the + icon in the top left to create a new session, then choose XFCE and click Launch.

If you are using SSH, you will use the same hostnames as described in how to connect with FASTX. For example, if you'd like to connect to machine 09 in Keller 1-250, you will do `ssh X500@csel-kh1250-09.cselabs.umn.edu`, where `X500` is your x500 ID that is registered as a CSE Labs account.

**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/kaung006`) will be persisted across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

### Diskquota Exceed
One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. <br>
To free up space, [see here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/CSE%20Disk%20Quota%20Exceeds)

## Retrieve Class Materials

1. Clone **public lab05** repo
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/public-lab05.git
    ```

2. Clone your **private lab05** repo<br>
    *Note: **replace** x500 with your x500*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/x500-lab05.git
    ```

3. Copy the contents of **public lab05** repo into your **private lab05** repo and you can start working inside your private repo.

### What's in lab05 folder?

-  <code>README.md</code> - lab05 instruction
-  <code>README_Project.md</code> - project instruction
-  <code>.gitignore</code>
-  <code>app</code> folder, which contains:
     -  <code>graph_viewer</code> - producing graph visualization
     -  <code>transit_service</code> - visualization
- <code>libs</code> folder, which contains:
     -  <code>routing</code> - finding the paths
     -  <code>trainsit</code> - entities properties
-  <code>dependencies</code>

## Doxygen

How to generate documentation for the code in this project and future projects. This can be done via Doxygen.

According to their [official website](https://www.doxygen.nl/index.html),
> Doxygen is the de facto standard tool for generating documentation from
> annotated C++ sources, but it also supports other popular programming languages
> such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and
> UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

Notice how the class [**some class**] has a description above the
class definition. Doxygen makes use of this to generate documentation for this
class. Doxygen also generates documentation for all functions of a class.

<br>

***NOTE: Students working on their personal machines will have to [download](https://www.doxygen.nl/manual/install.html) the
doxygen executable before continuing. CSE labs machines already have doxygen
installed. <br>
Windows .exe can be found here ->[download](https://www.doxygen.nl/files/doxygen-1.9.5-setup.exe)***

<br>

## Lab Instructions

### Goal
<hr>
  **The primary goal of this lab is for you to understand how to write code documentation in formatted way**
<hr>

1. Locate to your lab repo
    ```bash
    % cd <path_to_directory>
    ```
2. Create the configuration file.

    To start generating documentation, you must first generate a Doxygen
    configuration file in the docs directory. Run the following command from the
    lab05 directory (where this README is).

    ```
    mkdir docs
    doxygen -g docs/Doxyfile
    ```

    You will now see a new file **Doxyfile** in the <code>docs</code> directory.

3. Modify the Doxyfile to look in the <code>libs</code> folder when compiling (i.e, only the folder that was set as an Input will get the examination from doxygen). You can do this by setting the **INPUT** tag of your **Doxyfile**. Since this lab required you to write doxygen for only certain files/classes, you would need to point the Input to <code>libs/</code>. It should be around `line 832` within `Doxyfile`.

    ```
    INPUT                  = "../libs/"
    ```

    You would also want to set **RECURSIVE** tag of your **Doxyfile** to YES so that all the codes inside the folder you set for the input will be taken account for. Locate to `line 911` within `Doxyfile`.

    ````
    RECURSIVE              = YES
    ````
    
    Now, set the **EXCLUDE** tag to parsers and util folder. This tag is used if you do not want the doxygen to look at the provided path folders. You can find the EXCLUDE tag around `line 920`.
    ````
    EXCLUDE                  = "../libs/transit/include/util" "../libs/routing"
    ````

    The path is relative to the directory from which you run/compile the doxygen. ***It is important that you set it up to run from `docs/`***. Doxygen will not inform you if it does not find the src directory -- it just won't generate any files from your classes.


3. Generate the html pages for this lab. Run the following commands:
    ```
    cd docs
    doxygen Doxyfile
    ```
    You can now view the generated documentation from the `index.html` file in the
    `html` directory that was generated inside the docs folder. Open the `index.html` page which is refered to as the *landing page*. Explore the various menus to see how the comments in the code are organized in the html. Hover on the Classes menu and click on `Class Hierarchy`. Here, you will see somewhat a like of UML diagram.

4. Now modify the `/libs/transit/include/Drone.h` file to add Doxygen comments.
  
    Use **@brief** to describe the class's function, **@param** to describe the parameter, and **@return** to specify a function's return values. You can also refer to Doxygen's [manual](https://doxygen.nl/manual/docblocks.html) for their commenting standards.

    Example,
    ```
    /**
     * @brief The summation of two numbers.
     * 
     * @param a First number.
     * @param b Second number.
     * @return Result of adding two number.
     **/
    float sum(float a, float b) {
      return a+b;
    }
    ```

5. Files that you would need to document using doxygen:
  - /libs/transit/include/
    - Drone.h
    - IController.h
    - IEntity.h
    - Robot.h
    - SimulationModel.h
  
6. After you have written everything, recompile the doxygen (step 4) and click on the `classes` menu. If all the classes and its methods are displayed similar to the `Vector3 class`, then you are completed this lab.
7. Push all of your work to your github repo and follow the submission below.
<br>

### Final Submission

To submit your assignment, post on the Gradescope assignment "Lab 5: Doxygen" your x500 and the commit ID for your submission.
[Click here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/Commit%20ID) to see how to obtain commit ID.
