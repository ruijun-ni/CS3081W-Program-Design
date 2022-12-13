# 3081 Homework04 - New features
_(Due: Thursday, Dec. 16, 2022 @ 11:59pm)_

## General Information

### Team infomation

Team 001-9. Haibo Wang wan00220, Linghe Wang wang9257, Yanzheng Wu wu001026, Ruijun Ni nee00011

### Project Overview

This is a simulation that contain drone, robots, and 3D UMN map. We can schedule trips for robot on the map. The drone will pick up robot and send it to destination to finish the trip.

## How to run the simulation

### Accesing a Lab Machine

For this assignment, we suggest you use a lab machine in ***Keller Hall 1-250*** or ***Keller Hall 1-262*** ([details](https://cse.umn.edu/cseit/classrooms-labs#cselabs)). You can access a lab machine remotely using [VOLE](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/VOLE), FASTX, and [SSH](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/SSH). If you do not already have a CSE account, create the account following these [instructions](https://wwws.cs.umn.edu/account-management).

If you are using FASTX, you can access the machine by going to the webpage https://csel-kh1250-XX.cselabs.umn.edu where XX is the machine identifier number, and `kh1250` represents the machine is in the Keller 1-250 lab. In Keller 1-250, the machine numbers are 01-37, and in Keller 1-262 the machine numbers are 01-28. Please do not use the machine in the example below, choose a different one so the entire class isn't trying to work off of the same computer. For example, if you choose to use machine 09 in Keller 1-250, you should type into your web browser [https://csel-kh1250-09.cselabs.umn.edu](https://csel-kh1250-09.cselabs.umn.edu) to connect to your machine. Use your CSE account to login to the machine. One you login, click the + icon in the top left to create a new session, then choose XFCE and click Launch.

If you are using SSH, you will use the same hostnames as described in how to connect with FASTX. For example, if you'd like to connect to machine 09 in Keller 1-250, you will do `ssh X500@csel-kh1250-09.cselabs.umn.edu`, where `X500` is your x500 ID that is registered as a CSE Labs account.

**IMPORTANT: Inside the lab machine, only files saved to your home folder (e.g., `/home/kaung006`) will be persisted across sessions. If you log out, make sure your progress is pushed to GitHub or saved in the home folder.**

### Diskquota Exceed
One of the reasons you might not be able to log into a lab machine is that you reached your CSE Labs Account disk quota. <br>
To free up space, [see here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/CSE%20Disk%20Quota%20Exceeds)

### Retrieve Materials
You have two ways to get the materials

1. Clone **Team-001-9-homework04** repo
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/Team-001-9-homework04.git
    ```
2. Download the zip in the main branch.

### Compile and Run
1. Make sure your linux OS is installed and running. Locate to the root directory, then complie the program using following command.
    ```
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project 
    make -j
    ```
2. Please run the program using the following command.
    ```
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
   **Note**: If port 8081 is not available, choose a different port (e.g. 8082, 8083, etc...)
3. Navigate to http://127.0.0.1:8081 and you should see a visualization.

   Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.
4. Setting the start postion and destination by clikcing on 2D map in http://127.0.0.1:8081/schedule.html. Set the name of trip and moving strategy on      the upper left corner. Then, click the schedule trip in the lower left corner. Now, switch to http://127.0.0.1:8081, you can see the animation.

## What does the simulation do
We build a 3D map of UMN. There are robot and drone entities exist on this map. The drone will appear at its initialize position when you build the project. Then you can schedule trips by setting up the position and destination for the robot. The drone will finish scheduled trips one by one. At first, the drone will check if its current energy can support the trip. If it is, the drone will directly go to pick up the robot and send it to the destination. Otherwise, the drone will first go to the energy station to recharge. Then it will continue the trip(go to pick up the robot and send it to the destination). The project will show drone's current energy on the screen. We will have data.csv that in the root diretory of this project. 

## New features

### Drone Battery
We have add battery to the drone. The battery power will decrease as drone move and increase as drone recharge. The battery determine the curising distance of drone. It is interesting becasue the drone need to have a battery to make it realistic. Moving to the energy station and 3D model of energy station makes this simulation more entertain to look at. 

We choose decorator design pattern. It's a structural design pattern that lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors. The battery is the new behavior of drone, so we place drone inside battery wrapper object.

We create a battery class that inherit from IEntity. We modified drone factory. It creates the drone and warp it using battery. The battery is reponsible for the drone moving, battery consumption, and battery recharging. Because the drone entity no longer exists in the simulation entity list, it cannot get graph. Thus, we write a function "SetGraph" in battteryDecrator.cc to help drone get graph. 
 
The canArrive() function in batterDecorator.cc is responsible for checking if battery power is enought for the distance. 
Here is how distance calculated.
We add a new member variable to the Istrategy called "distance". We use euclidian distance to calculate the total distance of path for four strategies. When the trip scheduled, we calculate the total distance of picking up robot, drop off robot, and fly to power station. In order to make sure it can arrive the power station after one trip, we take in disctance of fly to power station as account. Then, we sum them up. The current energy must support the drone to finish the total distance, otherwise it will fly to power station and recharge. 

We also have a Update() function in batteryDecrator.cc. This function is responsible for updating the battery power. The battery power will increase when the drone recharge, decrease when the drone move. We will use canArrive() to check if the drone can finish the trip. If it is, the drone will directly go to pick up the robot and send it to the destination. Otherwise, it will go to recharge first, then it will continue the trip.



### Data Collection



## Sprint Retrospective
In this project, we applied Agile methodology for project management. We used Scrum to create a fixed-length iteration called "sprint". Before we started the sprint, our team created tasks we planned to do in the "Backlog". For example, we created tasks like "get idea checked off", "add charge station entity", "display battery level in frontend", etc. And then we start the sprint. We have *daily standup meetings* and assign tasks to teammates. Applying the Agile methodology improves flexibility, increases collaboration and transparency, and increases delivery speed. Agile encourages our team to work together and share information openly and transparently. This helps to foster a sense of teamwork and accountability among team members, and can lead to better collaboration and more efficient problem-solving. What went well in our sprint include meeting the sprint goals and objectives, delivering high-quality work, and maintaining good communication and collaboration within the team. What didn't go well in our sprint is that we experienced challenges and obstacles that slowed progress. For example, we encountered a bug when writting the battery decorator, which took us more time than estimated to finish this part. Then we communicated with teammates and decided to adjust our timeline and spent more time on this task, even devoting time in the weekend to get the task done. What we learned from using Agile sprint in this project is that it is important to plan ahead, to communicate openly and transparently with the team, and to monitor progress and adjust the plan as needed.
