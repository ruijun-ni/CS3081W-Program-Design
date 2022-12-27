FROM ubuntu:20.04
# ^ the above command signifies we will be using the ubuntu-20.04 OS in this image


# Install any available updates 
RUN apt update && DEBIAN_FRONTEND=noninteractive apt upgrade -y

# Create a directory called /app
RUN mkdir /app

# Copy the contents of copied-to-container/ to the /app directory inside the container.
COPY ./copied-to-container/ /app/