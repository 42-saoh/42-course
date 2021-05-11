FROM alpine:3.12.0
MAINTAINER saoh

COPY ./phpmyadmin /var/www/html/phpmyadmin

RUN apk update && apk add nginx
RUN apk add php7 php7-curl php7-fpm php-mbstring php-json php7-session php-mysqli
