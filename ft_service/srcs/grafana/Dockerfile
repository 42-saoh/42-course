FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add grafana --repository https://dl-cdn.alpinelinux.org/alpine/latest-stable/community/

COPY dashboards/ /usr/share/grafana/public/dashboards/

EXPOSE 3000

ENTRYPOINT ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]
