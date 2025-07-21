# ✅ Base image with build tools
FROM ubuntu:20.04

# ✅ Non-interactive to avoid tzdata prompts
ENV DEBIAN_FRONTEND=noninteractive

# ✅ Update & install necessary packages
RUN apt-get update && \
    apt-get install -y \
    cmake \
    g++ \
    make \
    vim \
    git \
    && rm -rf /var/lib/apt/lists/*

# ✅ Create app directory
WORKDIR /usr/src/app

# ✅ Copy all project files into container
COPY . .

# ✅ Build the project
RUN mkdir -p build && cd build && cmake .. && make

# ✅ Run the program (can override with docker run)
CMD ["./build/devbuddy"]
