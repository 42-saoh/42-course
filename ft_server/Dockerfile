FROM debian:buster
MAINTAINER saoh

ENV AUTOID on;

COPY srcs /srcs

RUN apt-get update && apt-get install -y nginx gnupg wget lsb-release
RUN apt-get install -y php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

CMD bash /srcs/start_conf.sh
