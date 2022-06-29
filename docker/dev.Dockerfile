FROM ubuntu:16.04

RUN apt-get update && DEBIAN_FRONTEND="noninteractive" apt-get install  -y \
    autoconf \
    automake \
    build-essential \
    cmake \
    curl \
    debhelper \
    git \
    libcurl4-openssl-dev \
    libprotobuf-dev \
    libssl-dev \
    libtool \
    lsb-release \
    ocaml \
    ocamlbuild \
    protobuf-compiler \
    python \
    wget \
    libboost-dev \
    tar \
    unzip

WORKDIR /linux-sgx
RUN wget https://download.01.org/intel-sgx/sgx-linux/2.7/distro/ubuntu16.04-server/sgx_linux_x64_sdk_2.7.100.4.bin

WORKDIR /opt/intel
RUN chmod +x /linux-sgx/sgx_linux_x64_sdk_2.7.100.4.bin && sh -c 'echo yes | /linux-sgx/sgx_linux_x64_sdk_2.7.100.4.bin'


#TODO install the rest of the necessary dependencies in order to build the project: such as the correct version of the sdk, I assume something like version between 2.7 and 2.9 since last commit was 2019.
#TODO openssl version 1.1.0i
#TODO find out which sgxssl version was used or necessary to avoid deprecated compilation bugs


WORKDIR /workspace
