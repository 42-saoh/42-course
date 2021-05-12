FROM alpine:3.12.0
MAINTAINER saoh

COPY default.conf /etc/nginx/
COPY nginx.sh /etc/nginx/

RUN apk update && apk add nginx openssh-server openssl
RUN apk add php7 php7-curl php7-fpm php-mbstring php-json php7-session php-mysqli

