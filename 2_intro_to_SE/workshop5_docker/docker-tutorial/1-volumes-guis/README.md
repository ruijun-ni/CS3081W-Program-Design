# 1: Docker volumes and GUI apps

## Build this image:

```bash
docker build -t 1-volumes-guis .
```

You can look at the Dockerfile to see what we're building into this image.

## Create container, connect now

Some new flags to the command:

`--volume` : Mount a volume from the host machine to the container

`--env` : Set environment variables in the container

`--privileged` : Give the container access to host machine resources. You should not use this in a production environment.

There are more flags, you can look these up on your own.

```
docker run -it --rm --name mycontainer-1-volumes-guis --group-add video --network host \
  --user=$(id -u $USER):$(id -g $USER) \
  --volume="/etc/group:/etc/group:ro" \
  --volume="/etc/passwd:/etc/passwd:ro" \
  --volume="/etc/shadow:/etc/shadow:ro" \
  --volume="/etc/sudoers.d:/etc/sudoers.d:ro" \
  --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
  --volume="/home/$USER:/home/$USER" \
  --workdir="$(pwd)" \
  --env="DISPLAY" \
  --privileged \
  mycontainer-1-volumes-guis /bin/bash
```

The above command is also in the `run-docker.sh` script in this folder.

To kill the docker run command and exit the container, press ctrl-d.

Connect to the container in VSCode:

Note: Your work **will** be saved, since we are attaching the host machine user's home folder to the container.

Note2: You don't actually need to open a new VSCode instance. You can just run the docker container, edit files normally here in VSCode, then run your program from the container.

1. Make sure you have the "Remote Explorer" extension installed.
2. Press ctrl-shift-p, then search and run `Remote-Containers: Attach to Running Container...`
3. Select the container with the name `mycontainer-volumes-guis`
4. A new VSCode instance will load. Open the folder called `/app`. Notice the `hello-world.bash` script is already here.
5. If you create a new terminal in this VSCode instance, you will be dropped into a bash shell in the container.