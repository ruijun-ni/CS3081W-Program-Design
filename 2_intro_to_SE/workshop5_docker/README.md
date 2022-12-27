# Workshop 5 - Docker


The purpose of this workshop is to teach you how to build docker images and deploy them. 
You will put your Lab 8 submission into a Docker container and upload the image to DockerHub. The 
submission for this workshop will be a link to your Docker image on DockerHub.

## What should be in this directory?

<ul>
  <li>  README.md
  <li>  Dockerfile
</ul>

## 1a Install Docker on your personal computer

### Windows 11

This is easy! Open an admin PowerShell terminal and run
```bash
wsl --install
```

Then download and Install Docker Desktop for Windows from this link: <br>https://docs.docker.com/desktop/install/windows-install/

You will use the newly installed Ubuntu environment to run the rest of the commands in this workshop.

### Windows 10

There are two parts to installing Docker on Windows. First, we must install Windows Subsystem for Linux 2 
(WSL2), then we can install Docker. WSL2 is the virtualized(ish) Linux Kernel for Windows and is used as a backend for 
Docker in Windows.

After that, the second step will be actually installing Docker.
1. Check for and install any Windows updates.
2. Make sure the Hyper-V feature for Windows is enabled, use the following guide: <br> https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/quick-start/enable-hyper-v
3. Follow steps 1-5 of this guide to install WSL2: <br> https://learn.microsoft.com/en-us/windows/wsl/install-manual
4. In an admin PowerShell terminal, run `wsl --install -d Ubuntu`
5. Let this run. A new window will pop up and eventually ask you for a UNIX username/password, go ahead and set these.
6. Download and Install Docker Desktop for Windows from this link: <br>https://docs.docker.com/desktop/install/windows-install/

You will use the newly installed Ubuntu environment to run the rest of the commands in this workshop.

### Linux

**Note:** This is only for installing on a personal linux machine, these install instructions 
will not work on lab machines.

Installation steps:

```shell
#download the installation script
curl -fsSL https://get.docker.com -o get-docker.sh
# run script
sudo sh get-docker.sh

# post install, need to add current user to docker group
sudo groupadd docker
sudo usermod -aG docker $USER
newgrp docker
```

### MacOS

1. Please follow the install instructions for Mac here: https://docs.docker.com/desktop/install/mac-install/, you can choose to install interactively or install from the command line. 

## 1b Docker on the CSE Machines

Instead of installing Docker on your personal machine, you can run Docker on the CSE Machines using the [QEMU](https://www.qemu.org/) hypervisor to create lightweight virtual machines.  These virtual machines allow us to run Docker.  Below are the steps:

### Note 1: Any work you do on a QEMU virtual machine is destroyed when you shutdown the machine. You will need to do this workshop in one sitting if you decide to use a CSE Labs machine.
### Note 2: You will not be able to test your Docker image on a QEMU virtual machine. You will need to ask a friend or find a computer with Docker installed in order to test your image.
1. Login to a CSE Lab machine through SSH. If you are using Windows, download and install the [PuTTy SSH client](https://www.putty.org/), then use the GUI to login to a machine.
    ```bash
    ssh X500@csel-kh1250-XX.cselabs.umn.edu
    ```
2. In the terminal, make sure you are running bash.
    ```bash
    bash
    ```
3. Resize your terminal to 80x25 (I know, it's weird, but qemu will report "Please resize your terminal to be 80x25" without it.)
4. Create the virtual machine with a random port.(___Note___: If for some reason the random port does not work, run the command again.  For example, it could report "Must specify a port greater than 1024".)
    ```bash
    % /project/qemu/bin/vm-start -n dockerhost -p ${RANDOM}
    ```
5. Wait until the virtual machine boots up...
6. Type `docker` and you should see a set of options.  Congratulations!  You can now run docker on the CSE Lab Machines
7. To power off your machine do type poweroff:
    ```bash
    % poweroff
    ```
8. To restart your machine go back to Step 4.

## 2. Pulling and Running a Docker Image

We will now test pulling and running a Docker image.

1. On a machine with Docker installed use the Ubuntu environment/terminal to pull a hello-world image from [Docker Hub](https://hub.docker.com/).  This is similar to `git clone` or `git pull`
    ```shell
    docker pull hello-world
    ```
2. Now we'll run a container based on the `hello-world` image:
    ```shell
    docker run --rm hello-world
    ```
   You should see the following printed on the screen:
   ```
   Hello from Docker!
   This message shows that your installation appears to be working correctly.
   
   ...
   ```
3. You can delete an image from your computer with the following command:
   ```shell
   docker image rm hello-world
   ```

## 3. Building and running your own Docker image

We're going to build our own Docker image that will contain your Lab 8 simulation. Use the 
provided Dockerfile as a template.

Steps:

1. Clone this repository and cd to the repo.
   ```bash
   git clone https://github.umn.edu/umn-csci-3081-F22/public-workshop5.git
   
   cd public-workshop5
   ```
2. Clone the Lab 9 base code from GitHub into this directory.
   ```bash
   git clone https://github.umn.edu/umn-csci-3081-F22/public-lab09.git
   ```
   (This is the fully working Lab 8 code that you start with for Lab 9. If you are finished with Lab 9
   and want to use your working code instead, you may do so.)
3. Open the provided Dockerfile and modify it in order to create an image that contains and runs your Lab 9 simulation.
4. When you're ready to build your image, run the following command:
   ```bash
   docker build -t workshop5 .
   ```
5. If you are using your local machine, now you can run a container with your new image using the following command:
   
   ```bash
   docker run -it --rm -p 8081:8081 workshop5
   ```

6. Navigate to [http://localhost:8081/schedule.html](http://localhost:8081/schedule.html) to view your simulation, and [http://localhost:8081/schedule.html](http://localhost:8081/schedule.html) to schedule a trip.
   
   **Note: If you are using a QEMU VM on the CSELabs machine, you will not be able to view the website as we cannot easily forward the webserver to your local machine.
   You will need to verify that the webserver works on a different computer running Docker.** 

## 4. Pushing your image to DockerHub

DockerHub is a website that we use to host Docker images. Think of this like GitHub, but for Docker images. 

1. Create an account on [Docker Hub](https://hub.docker.com/).
2. Create a new public repository called `workshop5`.
3. In your terminal, login to DockerHub with your credentials.
    ```bash
    docker login --username=<DockerHub username>
    ```
3. Rename the workshop5 image to match your username. **Note: the image name MUST match your repository name**
    ```bash
    docker tag workshop5 <DockerHub username>/workshop5
    ```
4. Push the image to your repository.
    ```bash
    docker push <DockerHub username>/workshop5
    ```
5. Navigate to your repository on DockerHub to make sure your image has been successfully pushed.


## 5. Submission

Your submission will be on GradeScope. Submit a link to your DockerHub repo that contains your working Docker image. 
If you worked with a friend or two, make sure to add these people to your GradeScope Submission. 

**Note:** Delete, pull your image from DockerHub, then run a container to make sure your uploaded image works properly. 

Grading Criteria:

|    Points     | Description                                                                                      |
|:-------------:|:-------------------------------------------------------------------------------------------------|
|    100/100    | Your image is on DockerHub, we can pull and run your image and the simulation works.             |
|    50/100     | Your image is on DockerHub, but when we pull and run your image and the simulation doesn't work. |
|     0/100     | No DockerHub link/no submission                                                                  |
