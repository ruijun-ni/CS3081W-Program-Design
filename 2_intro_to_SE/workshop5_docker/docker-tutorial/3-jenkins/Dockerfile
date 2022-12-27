FROM jenkins/jenkins:lts-jdk11
# if we want to install via apt
USER root
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y python3 python3-pip curl sudo

RUN curl -fsSL https://get.docker.com -o get-docker.sh

RUN sh ./get-docker.sh

RUN usermod -aG docker jenkins

# Install firefox, pip3, opencv dependencies
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y ffmpeg libsm6 libxext6

# Install opencv, dependencies for face detection
RUN pip3 install --no-cache-dir --upgrade pip && pip3 install --upgrade --no-cache-dir scipy matplotlib opencv-python pytest

USER jenkins