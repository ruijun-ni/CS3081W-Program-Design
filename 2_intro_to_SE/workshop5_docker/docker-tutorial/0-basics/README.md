# 0: Docker basics

## Linux Docker Install

```bash
curl -fsSL https://get.docker.com -o get-docker.sh

sudo sh get-docker.sh

sudo groupadd docker

sudo usermod -aG docker $USER

newgrp docker

docker run --rm hello-world
```

## Build this image:

```bash
docker build -t 0-basics .
```

You can look at the Dockerfile to see what we're building into this image.

## Container Workflow: 
Either create a container, start it, then connect later, or create container, start it, and connect immediately. We will be exploring the latter option.

### Create container, connect now!

This is the simplest way to create a container and start interacting with it now.

```bash
docker run -it --rm --name mycontainer-basics 0-basics /bin/bash
```

To kill the docker run command and exit the container, press ctrl-d.

Connect to the container in VSCode:

**Note: None of your work will be saved. You're editing files inside the container and the container will be destroyed once you kill the docker run command**

1. Make sure you have the "Remote Explorer" extension installed.
2. Press ctrl-shift-p, then search and run `Remote-Containers: Attach to Running Container...`
3. Select the container with the name `mycontainer-basics`
4. A new VSCode instance will load. Open the folder called `/app`. Notice the `hello-world.bash` script is already here.
5. If you create a new terminal in this VSCode instance, you will be dropped into a bash shell in the container.