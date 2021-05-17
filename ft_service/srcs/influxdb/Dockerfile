FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add influxdb --repository http://dl-2.alpinelinux.org/alpine/edge/community/
RUN mkdir -p /etc/influxdb
RUN mkdir -p /var/lib/influxdb

COPY influxdb.conf /etc/vsftpd/influxdb.conf
COPY influxdb.sh /usr/sbin/

RUN chmod +x /usr/sbin/influxdb.sh

EXPOSE 8086

ENTRYPOINT ["usr/sbin/influxdb.sh"]
