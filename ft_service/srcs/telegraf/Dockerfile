FROM alpine:3.12.0
MAINTAINER saoh

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz
RUN tar -C . -xzf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN cp -r telegraf-1.15.3/* /

COPY telegraf.sh /usr/sbin/

RUN chmod +x /usr/sbin/telegraf.sh

ENTRYPOINT ["usr/sbin/telegraf.sh"]
