FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add mysql mysql-client

COPY mysql.sh /usr/sbin/mysql.sh
COPY my.cnf /etc/my.cnf

RUN chmod 644 /etc/my.cnf
RUN chmod +x /usr/sbin/mysql.sh

EXPOSE 3306

ENTRYPOINT ["/usr/sbin/mysql.sh"]
