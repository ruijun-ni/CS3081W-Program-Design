#!/bin/bash

# Corey Knutson, 2022-12-05

docker run --rm --network host \
  --user=$(id -u $USER):$(id -g $USER) \
  --volume="/var/lib/jenkins:/var/lib/jenkins:rw" \
  --workdir="$(pwd)" \
  rogueraptor7/1-volumes-guis /bin/bash -c "$*"