# 3081 Lab10 - Import Assets
_(Due: Thursday, Nov. 17, 2022 @ 11:59pm)_

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

1. Clone **public lab010** repo
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/public-lab10.git
    ```

2. Clone your **private lab10** repo<br>
    *Note: **replace** Team-XXX-X with your lecture section and team number* <br>
    *Example: Team-001-1-lab10*
    ```bash
    git clone git@github.umn.edu:umn-csci-3081-F22/Team-XXX-X-lab10.git
    ```

3. Copy the contents of **public lab10** repo into your **private lab10** repo and you can start working inside your private repo.

## Lab Instructions

### Goal
<hr>
  **The primary goal of this lab is for you to know how to add assets (i.e., models) into the simulation and prepare you for the final project.**
<hr>

## Tasks
| ID | Title | Task Summary Description | Task Deliverable |
| :---: | --- | --- | --- |
| Task 1 | Assets | Add car to the simulation | Source Code |
| Task 2 | Assets | Add helicopter to the simulation | Source Code |
| Task 3 | Create Button | Create button on webpage (front-end) to support the creation of multiple helicopters | HTML and Javascript |
| Task 4 | Assets | Implement your own idea | Source Code |
| Task 5 | Doxygen | Create documentation of the classes/functions that you create | HTML |
| Task 6 | Code Styling | Match your code style with Google style guidlines | Source Code |

### Tested Working Assets
Tested working models for the simulation can be found on [class github](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/Project_Assets)

You can find the image of the models that is provided in github can be found on [google doc](https://docs.google.com/document/d/1xBie-fZT6m-M_MTB_RlRrr0GqpheRcoc3m7pbydXzoI/edit?usp=sharing)

### Task 1 (Car)
Steps:
1. Download car model from either [class github](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/Project_Assets) or other sources.
   - *Important: File must be .glb format*
2. Place the car model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Car` entity class. This class will do nothing except moving from its position toward the destination (chosen randomly).
   - Must use Astar strategy to move around
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < Infinity
        -800  < z < 800
        ```
4. Add `CarFactory` to the existing composite factory design pattern.
   - type: "car"
5. When the webpage starts to run, it will call the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add new json object inside the umn.json to **create** a car right at the start of the scene with the followings info:
   ```
    "type": "car",
    "name": "Car",
    "mesh": "assets/model/car.glb",
    "position": [x, y, z],
    "scale": [xScale, yScale, zScale],
    "rotation": [0, 0, 0, 0],
    "direction": [1,0,0],
    "speed": 50.0,
    "offset": [0, 0.6, 0]
   ```
   `mesh` = model file location<br>
   `position` = your choice as long as it's within the map <br>
   `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the car should be created and moving around as soon as you start the webpage.

### Task 2 (Helicopter)
Steps:
1. Download helicopter model from either [class github](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/Project_Assets) or other sources.
   - *Important: File must be .glb format*
2. Place the helicopter model under `<project>/apps/transit_service/web/assets/model/` folder.
3. Create the `Helicopter` entity class. This class will do nothing except moving from its position toward the destination (chosen randomly).
   - Will use Beeline strategy to move around
   - XYZ Bounding:
        ```
        -1400 < x < 1500
         240  < y < Infinity
        -800  < z < 800
        ```
4. Add `HelicopterFactory` to the existing composite factory design pattern.
   - type: "helicopter"
5. When the webpage starts to run, it will call the `umn.json` file which can be found under `<project>/apps/transit_service/web/scenes/umn.json`
6. Add new json object inside the umn.json to **create** a helicopter right at the start of the scene with the followings info:
   ```
    "type": "helicopter",
    "name": "Helicopter",
    "mesh": "assets/model/helicopter.glb",
    "position": [x, y, z],
    "scale": [xScale, yScale, zScale],
    "rotation": [0, 0, 0, 0],
    "direction": [1,0,0],
    "speed": 40.0,
    "offset": [0, -0.5, 0]
   ```
   `mesh` = model file location<br>
   `position` = your choice as long as it's within the map <br>
   `scale` = make it look like real life size (i.e., not too small or too large)
7. If you did all of the steps above correctly, now the helicopter should be created and moving around as soon as you start the webpage.

### Task 3 (Create Button)
Steps:
1. You will need to use some HTML and Javascript for this task.
2. HTML will be use to display the button to the users and Javascript will be use to move the data from the front-end to the back-end.
3. The button will be created under the schedule page which can be found at `<project>\apps\transit_service\web\schedule.html`
4. We want to create the `Add Helicopter` button below the Schedule Trip. Therefore, first find the location of the `Schedule Trip` button.
   - Button syntax: `<input type="button" value="Text to Display">`
   - onClick(): When the button is clicked, it will call to the given function here. 
5. Under the schedule trip button, create a button which displays `Add Helicopter` and it will call `addHelicopter()` function.
6. Currently, the schedule trip button and add helicopter button are too close together, we want it to seperate a bit. Add `style="margin-top: 10px;"` inside the existing add helicopter button element. 
7. Inside the script create a function which will use the api to send the data to the back-end. The function name must be `addHelicopter()`. As an guide, check out the `function schedule() {...}` on how to create a function using Javascript.
8. Inside this addHelicopter() function, first call the api to create an entity with the following json data:
   ```
   "type": "helicopter",
   "name": "Helicopter-"+helicopterID,
   "mesh": "assets/model/helicopter.glb",
   "position": [700, 290, 400],
   "scale": [xScale, yScale, zScale],
   "direction": [1, 0, 0],
   "speed": 40.0,
   "offset": [0, 0.6, 0]
   ```
   `mesh` = model file location<br>
   `scale` = make it look like real life size (i.e., not too small or too large)
9. Add helicopterID += 1 after you call the api as this will increment the helicopter ID.
10. If you did all of the steps above correctly, now the helicopters will sqawn if you click `Add Helicopter` button.

### Task 4 (Implement your own idea)
For this task, create at least **one** new entity of your own choice and you can decide what you want this entity to do. This entity should **at least** created once when the simulation start. *Be creative as much as possible*.

**Important: Your entity should be doing something.**

Example ideas:
   - High speed jet aircraft or sports car
   - Kangroo hopping when travelling to the destination
   - Ghost entity which can pass through the buildings
   - Flying witch

### Task 5 (Doxygen)
Write Doxygen for all the **NEW** classes you create (public members only). Which in our case for this lab, are as follows:
- Car
- CarFactory
- Helicopter
- HelicopterFactory
- \<Your own idea entity>
- \<Your own idea entity Factory>

### Task 6 (Code Style)
Match your new code's style with Google Code Styling guide. Which in our case for this lab, is as follow:
- Car
- CarFactory
- Helicopter
- HelicopterFactory
- \<Your own idea entity>
- \<Your own idea entity Factory>

### Final Submission

To submit your assignment, post on the Gradescope assignment "Lab 10: Import Assets" your team repo link and the final commit ID for your submission.
[Click here](https://github.umn.edu/umn-csci-3081-F22/shared-upstream/tree/main/FAQs/Commit%20ID) to see how to obtain commit ID.
