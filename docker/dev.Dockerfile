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
RUN wget https://download.01.org/intel-sgx/sgx-linux/2.13.3/distro/ubuntu16.04-server/sgx_linux_x64_driver_2.11.0_2d2b795.bin

WORKDIR /opt/intel
RUN chmod +x /linux-sgx/sgx_linux_x64_sdk_2.15.101.1.bin && sh -c 'echo yes | /linux-sgx/sgx_linux_x64_driver_2.11.0_2d2b795.bin'

WORKDIR /workspace
