FROM ubuntu:16.04

RUN apt-get update

RUN apt-get install build-essential  -y
RUN apt-get install wget -y
RUN apt-get install gcc -y
RUN apt-get install clang -y
RUN apt-get install g++ -y
RUN apt-get install libsfml-dev -y
RUN apt-get install libopencv-dev -y
RUN apt-get install cmake -y
RUN apt-get install make -y
RUN apt-get install -y mesa-common-dev freeglut3-dev libglew-dev

COPY . /usr/src/
WORKDIR /usr/src/

# Сборка
RUN make

#Запуск
CMD ["./exec"]
