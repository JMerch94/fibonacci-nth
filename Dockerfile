FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y

RUN apt-get -y install clang

COPY . /usr/src/fibonacci-nth

WORKDIR /usr/src/fibonacci-nth

RUN clang++ -o fibonacci-nth main.cpp

CMD ["./fibonacci-nth"]