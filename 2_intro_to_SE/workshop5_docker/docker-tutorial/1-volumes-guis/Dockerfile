FROM ubuntu:20.04
# ^ the above command signifies we will be using the ubuntu-20.04 OS in this image

# Install any available updates 
RUN apt update && DEBIAN_FRONTEND=noninteractive apt upgrade -y

# Install firefox, pip3, opencv dependencies
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y firefox python3-pip ffmpeg libsm6 libxext6 sudo

# Install opencv, dependencies for face detection
RUN pip3 install --no-cache-dir --upgrade pip && pip3 install --upgrade --no-cache-dir scipy matplotlib opencv-python pytest