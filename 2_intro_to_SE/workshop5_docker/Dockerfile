# Use Ubuntu 20.04 as our base operating system
FROM ubuntu:20.04

# RUN will run a command in the container. The following command installs basic buid tools and dependencies for building the Lab 8 code.

RUN apt-get update && apt-get install -y \
    build-essential \
    libssl-dev \
    zlib1g-dev

# Let's make a new folder called /app . This is where we'll put our project code
RUN mkdir -p /app

# Change directories to /app . All following commands will be run from this directory
WORKDIR /app


# Uncomment the following line and modify the <..> to copy FROM the first path on the host machine TO the second path in the container
# COPY <lab 9 repository path> <app path>
COPY ./public-lab09 /app

# Build the project code. Replace <..> with the proper command
# RUN <..>
RUN make -j

# CMD will run a command when the container is started. Run the command to start the project webserver.
# CMD <..>
CMD ./build/bin/transit_service 8081 apps/transit_service/web/