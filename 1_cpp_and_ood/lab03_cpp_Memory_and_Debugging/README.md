# 3081 Lab03 - C++ Memory and Debugging
_(Due: Thursday, September. 29, 2022 @ 11:59pm)_

## What You Will Learn

1. Understand memory allocations
2. How to enter the gdb environment
3. How to use gdb commands to debug your programs
4. How to detect memory inefficiencies using Valgrind

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

1. Clone **public lab03** repo
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/public-lab03.git
    ```

2. Clone your **private lab03** repo<br>
    *Note: **replace** x500 with your x500*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/x500-lab03.git
    ```

3. Copy the contents of **public lab03** repo into your **private lab03** repo and you can start working inside your private repo.

### What's in lab03 folder?

- part_1

  - Makefile:
    - This makefile is provided to allow you an easy start to configure and build the executables.
  - memory.cc:
    - This contains the main function for the Gradescope assignment below.
  
- part_2
  
  - Makefile:
    - This makefile is provided to allow you an easy start to configure and build the executables.
  - drone.cc/.h
  - entity.cc/.h
  - main.cc/.h
  - robot.cc/.h
  - tree.cc/.h

- README.md:
  - You're reading this now.

## Lab Instructions

### Goal
<hr>
  **The primary goal of this lab is for you to understand C++ memory concepts (Part 1) and Debug the given code using GDB and checking memory leaks (Part 2).**
<hr>

### Part 1 - Understanding C++ Memory (Gradescope assignment - 50% of Lab03 Grade)

Part 1 consists of running the `memory_app` program and answering questions on the Gradescope Lab 3 Part 1 assignment.  You can take the assignment multiple times and the highest score will be used.  **Note:** You are welcome to modify `memory.cc` to help answer any questions.

#### Executing Lab Code 

Build the executable using the makefile and run the executable.
```bash
% <Locate to the repo first>
% cd part_1
% make
% ./memory_app
```

#### Type Sizes

Run the following and study the `type_sizes()` function within `memory.cc`.  This function lists out the sizes for different types and the sizes of variables in memory:

```
% ./memory_app type_sizes
```

Answer questions 1-5 in the Gradescope assignment.

#### Private Variables

Run the following and study the `private_variables()` function within `memory.cc`.  This function casts a DVec3 to a double array:

```
% ./memory_app private_variables
```

Answer question 6 in the Gradescope assignment.

#### Byte Arrays

Run the following and study the `byte_arrays()` function within `memory.cc`.  This function converts an integer into a byte array:

```
% ./memory_app byte_arrays
```

Answer questions 7-8 in the Gradescope assignment.

#### Arrays

Run the following and study the `arrays()` function within `memory.cc`.  This function investigates the buffer overflow problem:

```
% ./memory_app arrays
```

Answer questions 9-10 in the Gradescope assignment.


### Part 2 - Debugging with GDB (50% of Lab03 Grade)

#### What You Will Learn

1. How to add the debugging flag to your Makefile compilation targets
2. How to enter the gdb environment
3. How to use gdb commands to debug your programs
4. How to detect memory inefficiencies using Valgrind

#### Instructions

1. First, build the example program with _make_.

    ```bash
    % <Locate to the repo first>
    % cd part_2
    % make
    ```
2. Then, run the program:
    ````
    $ ./entity_app
    ````
    See that the program quits in a Segmentation Fault. In the following steps, we will try to diagnose the problem.

3. You need to compile the code so that it can be run inside the GDB debugger. This is a flag that can be set in the Makefile. For each of the compilation statements in the makefile, we need the `-g` flag.  We can do this by adding -g to CXXFLAGS to tell the compiler to generate debug code. For example:

    ````
    CXXFLAGS = -std=c++11 -g
    ````

    Now, recreate the executable, with the debugging flags used this time.

    ````
	$ make clean
	$ make
	````

4. Start a debugging session on an executable file by typing _gdb <executable>_
    ````
    $ gdb entity_app
    ````

5. Once in the debugger session (the prompt will change to (**gdb**)), execute the program with _run_.
6. The program _entity_app_ will run and crash with the following output (your output may look slightly different):
    ````
    (gdb) run
    Starting program: /home/user/repo/lab03/partB/entity_app 
    warning: Error disabling address space randomization: Operation not permitted

    Program received signal SIGSEGV, Segmentation fault.
    0x000055c43e2c805b in Tree::Tree (this=0x55c43ff72f50, name="Oak", x=50, y=50)
        at tree.h:11
    9	        pos[0] = x;
    ````

7. Attempt to discover where (and why) in the provided code, the fault is occurring.
In this case, the line number causing the error is provided. If the location is not in the provided code, use the _gdb bt_ command (bt stands for "backtrace") to determine where the fault occurs. Type _bt_ now to see the where the execution stopped in each method:
    ````
    (gdb) bt
    #0  0x0000557bef78e0ab in Tree::Tree (this=0x557bf0c4af50, name="Oak", x=50, 
        y=50) at tree.h:11
    #1  0x0000557bef78d918 in main (argc=1, argv=0x7ffe5db81d18) at main.cc:38
    ````

    The backtrace shows that execution stopped in the method _Tree(name, x, y)_ constructor. This constructor was called from _main()_ on line 38 of _main.cc_.

    The above backtrace indicates that the error happened on line 11 of _tree.h_. Edit the file, and look at line 11. Why is this causing an error?

    Let's fix this error by modifying the code in _tree.h_.  We can use gdb to print out the variables using the debugger.  Try the following:

    ````
    (gdb) print x
    $1 = 50
    (gdb) print y
    $2 = 50
    (gdb) print pos
    $3 = (double *) 0x0
    ````

    On line 11 of Tree.h, it appears we are trying to set values into the _pos_ array, which is NULL.  The easiest solution is to create the array on the stack instead of an uninitalized pointer.  Instead of `double* pos` we can define it as `double pos[2]`.  Recompile _entity_app_ with _make_, and run the program again.

8. We see another segfault, so let's start the debugger (steps 4-6).  Now we get the following output when we type _bt_ for viewing the backtrace:

    ````
	(gdb) bt
	#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
	#1  0x00007ffff7a6b859 in __GI_abort () at abort.c:79
	#2  0x00007ffff7ad626e in __libc_message (action=action@entry=do_abort, 
	    fmt=fmt@entry=0x7ffff7c00298 "%s\n") at ../sysdeps/posix/libc_fatal.c:155
	#3  0x00007ffff7ade2fc in malloc_printerr (
	    str=str@entry=0x7ffff7bfe4d9 "free(): invalid size") at malloc.c:5347
	#4  0x00007ffff7adfb3c in _int_free (av=<optimized out>, p=0x7fffffffd2f0, 
	    have_lock=0) at malloc.c:4177
	#5  0x0000555555556cfb in main (argc=1, argv=0x7fffffffd448) at main.cc:69
    ````

    Fortunately, _gdb_ allows users to navigate the backtrace by typing _up_ and _down_.  When output looks like the above, often it is easiest to look for the highest file in your code.  In this case it is _main.cc:69_.  Let's traverse the backtrace to this location with the _up_ command.  We want to go up 6 levels in the backtrace to #5:

    ````
    (gdb) up 5
    #5  0x000055d95b797de3 in main (argc=1, argv=0x7ffc388ffd58) at main.cc:69
    69	      delete entities[i];
    ````

    Now that we are at this level of the backtrace, we can use _print_ to find out more information.  For example, we can print the entities and the specific entity we are trying to delete by printing i.  We can also print other information:

    ````
	(gdb) print entities
	$1 = std::vector of length 6, capacity 8 = {0x7fffffffd300, 0x55555556ef90, 
	  0x55555556efe0, 0x55555556f060, 0x55555556eef0, 0x55555556f0e0}
	(gdb) print i
	$2 = 0
	(gdb) print entities[0]
	$3 = (Entity *) 0x7fffffffd300
	(gdb) print entities[0]->GetName()
	$4 = "Entity"
    ````

    Notice how the _up_, _down_, and _print_ commands help us find out more information.  In this case, the problem appears to be with trying to delete the first entity in the vector.  Fix the problem, recompile _entity_app_ with _make_, and run the program again.  You may fix the problem howevever you like.

    There are several causes of "Segmentation faults" in this program. Use _gdb_ to help to identify and fix each issue until it runs correctly (see step 7). You might find the commands _up_ and _print_ particularly useful.

9. If the program run smoothly without any errors then you won't be able to use the _bt_ command anymore. So how can we get into certain areas and check out the data? The answer is to use the break point, you can simply set the break point to the lines that you would like to stop and inspect at. For example, if you would like to stop and inspect the start of the main function, do the following:
	````
	(gdb) break main
	Breakpoint 1 at 0x5555555565eb: file main.cc, line 10.
	(gdb) run
	Starting program: /home/user/repo/labs/lab03/partB/entity_app
	Breakpoint 1, main (argc=32767, argv=0x7ffff7fb3880) at main.cc:10
	10	int main(int argc, char**argv) {
	````
	This will pause the program at the main function and you can continue to run the program line by line:
	````
	(gdb) n
	13	  int iterations = 3;
	(gdb) n
	14	  double dt = 0.1;
	(gdb) n
	15	  if (argc > 1) {
	````
	Checkout the GDB Quick Guide: [click here](https://condor.depaul.edu/glancast/373class/docs/gdb.html)
	
10. In this program there is a base class called Entity.  MovableEntity and Tree inherit directly from Entity.  Drone and Robot inherit from MoveableEntity.  A robot moves around in a circle of a specified radius and a drone moves in a direction at a specified velocity.  A tree stays in one place.  When your program is running correctly, running the executable should exactly produce the following output:

    ````
    Time = 0:
    --------------
    Drone-A, 0, 0, 0
    Oak, 50, 50
    Johnny-Five, 1, 0
    Maple, 100, 100
    Drone-X, 0, 0, 0
    Dave, 4, 0

    Time = 0.1:
    --------------
    Drone-A, 0.0707107, 0.0707107, 0.1
    Oak, 50, 50
    Johnny-Five, 0.995004, 0.0998334
    Maple, 100, 100
    Drone-X, 0.1, 0, 0.1
    Dave, 3.98002, 0.399334

    Time = 0.2:
    --------------
    Drone-A, 0.141421, 0.141421, 0.2
    Oak, 50, 50
    Johnny-Five, 0.980067, 0.198669
    Maple, 100, 100
    Drone-X, 0.2, 0, 0.2
    Dave, 3.92027, 0.794677

    Simulation Complete
    ````

    If your output does not look like the above, you will need to continue debugging your program to get the correct output.  Most likely, there are other bugs in the program besides segfaults.  Consider the following common errors to look for:

     - **Virtual Methods** - Check to see whether methods are polymorphic.  Should some of the methods be declared virtual.
     - **Arrays (Required - implement this change)** - Using double* arrays as arguments and return types is often not safe.  Bad things usually do happen!  For example is hard to tell how big the array is and we might accidently overwrite a pointer.  Change these into a std::vector<double> or user defined class (e.g. Vector3) instead of double*.  An added bonus of using std::vector<double> is you can get the size of the array.
     - **Virtual Destructors** - If a base class does not have a virtual destructor, subclass destructors will not be called.
     - **Referencing Parameters** - It is possible to send in a pointer or reference into a method or constructor and set the memory address, however, that parameter may go out of scope or get deleted elsewhere in the program.
     - **Unique Pointers** - If you are using dynamic memory, it's often a good idea to use a unique_ptr<type> instead of _new_ and _delete_ if possible.  This way, the pointer will be deleted by the unique_ptr and there will not be a memory leak.
     - **new / delete** - Remember anytime we add an object to the heap with _new_ we must also _delete_ it.  Also, be sure to use the correct forms of new and delete.  For example if you create an array with _new_ be sure to use _delete[]_ when you delete it.
     - **Casting** - Be sure to use static_cast<>, dynamic_cast<>, and reinterpret_cast<> correctly.
	
     **Note: You may fix these errors however you want.  Perhaps consider adding more polymorphic methods or changing method signitures (return types / parameters).**

11. If you're familiar with Java, you know that the jvm handles recycling the memory dynamically allocated in the heap. However, in C/C++ the memory is not recycled automatically, meaning your program is prone to memory leakage where your programs can run out memory. All the memory that is allocated dynamically must be recycled using  [`free(void*)`](http://www.cplusplus.com/reference/cstdlib/free/) which should be used when using `malloc`,`calloc` which are used in the C programming language memory calls. Since we are programming in C++ these should not be used in this class.

    In C++, the `new` operator is used to dynamically allocate memory. When using the `new` operator you need to use `delete ptrName`. Click [`here`](https://www.geeksforgeeks.org/g-fact-30/) for more information. When dynamically allocating an array using `new [] ` you need to use `delete [] ptrName`. Click [`here`](http://www.cplusplus.com/reference/new/operator%20delete[]/) for more information. **Note: `delete/delete[]` are specific to C++ while `free` works on both C/C++.**  

    With this information, you might be thinking, how can I detect possible memory leaks?  

    This is where using `Valgrind` is helpful in detecting memory leaks. Click [here](https://valgrind.org/docs/manual/quick-start.html) to reference the manual. The Valgrind tool suite provides a number of debugging and profiling tools that help you make your programs faster and more correct. The most popular of these tools is called **Memcheck**. Memcheck helps you by identifying possible memory-related issues in your C/C++ programs.

> ### Note: Step 11 depends on the successful completion of step 10, so please make sure you finish step 10 before completing this step. 

### To run Valgrind on your program follow the steps below:

  * Make sure Valgrind is installed in your system (Valgrind is by default installed on CSE machines and the docker environment) by typing `valgrind` in your command prompt. If you're using your own linux machine, on command prompt run `sudo apt install valgrind`.
  
  * Make sure you compile your code in debugging mode, just like the steps above in running gdb.
  
  * Then, assuming your program `program` needs two arguments `arg1 arg2`to run on the command prompt (e.g. `./program arg1 arg2`), simply run `valgrind --leak-check=yes ./program arg1 arg2`

    After running valgrind, if the end of your output looks like below, then you've completed the coding part of the lab!

    ````
    % valgrind --leak-check=yes ./entity_app 

    ==1660== Memcheck, a memory error detector
    ==1660== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==1660== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
    ==1660== Command: ./entity_app
    ==1660== 

    Drone-A, 0.0707107, 0.0707107, 0.1
    Oak, 50, 50
    Johnny-Five, 0.995004, 0.0998334
    Maple, 100, 100
    Drone-X, 0.1, 0, 0.1
    Dave, 3.98002, 0.399334

    Time = 0.2:
    --------------
    Drone-A, 0.141421, 0.141421, 0.2
    Oak, 50, 50
    Johnny-Five, 0.980067, 0.198669
    Maple, 100, 100
    Drone-X, 0.2, 0, 0.2
    Dave, 3.92027, 0.794677

    Simulation Complete
    ==1661== 
    ==1661== HEAP SUMMARY:
    ==1661==     in use at exit: 0 bytes in 0 blocks
    ==1661==   total heap usage: 16 allocs, 16 frees, 74,280 bytes allocated
    ==1661== 
    ==1661== All heap blocks were freed -- no leaks are possible
    ==1661== 

    ````

    If not, don't worry: all you need to do is delete all the dynamically allocated memory using the **appropriate** deallocation methods. Here's a [link](http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/messages.html) that talks about some common error messages on Valgrind Memcheck.

    When your output looks like the output in step 10 and there are no memory leaks from step 11, you have completed the coding part of the lab!


### Final Submission
_(Gradescope submission will be available on Friday, September 23th, 2022)_

Submit your work by completing the two tasks below:

#### Part 1
- Complete the Lab03 Part 1 Gradescope assignment (you may take this multiple times).

You are welcome to keep changing and submitting this lab up to the deadline.  Gradescope will recompile and test your code.  If for some reason the automated feedback does not work for you, TAs can also manually verify your submission.

#### Part 2
- Push all of your codes inside the part_2 to github.

Then post on the Gradescope assignment "Lab 3 Part 2: Memory and Debugging" your x500 and the commit ID for your submission.
[Click here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/Commit%20ID) to see how to obtain commit ID.
