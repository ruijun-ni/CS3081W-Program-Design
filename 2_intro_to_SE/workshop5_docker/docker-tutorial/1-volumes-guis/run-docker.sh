#!/bin/bash

# Corey Knutson, 2022-12-05
# Note: the --privileged flag will give the container access to devices on your host machine. Use at your own risk.

docker run -it --rm --name mycontainer-$1 --group-add video --network host \
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
  $1 /bin/bash