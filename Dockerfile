FROM alpine
RUN apk add; apk add make \
    musl-dev \
    g++ \
    valgrind \
    gtest \
    bash \
    gtest-dev \
    fish
COPY . /project
WORKDIR /project
ENTRYPOINT [ "/bin/bash" ]
