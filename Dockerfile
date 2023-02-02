FROM ubuntu:20.04

# Install any needed packages specified in requirements.txt
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
    # Development files
    build-essential \
    git \
    bzip2 \
    wget && \
    apt-get clean
RUN wget -qO- https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2 | tar -xj

ENV PATH "/gcc-arm-none-eabi-9-2019-q4-major/bin:$PATH"

RUN git clone https://github.com/Maxkgo/MaxkGo-BMS-Firmware.git
RUN cd MaxkGo-BMS-Firmware && git checkout dev



