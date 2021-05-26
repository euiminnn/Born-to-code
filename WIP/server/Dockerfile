FROM  debian:buster

RUN apt-get update
RUN apt-get upgrade

RUN apt-get -y install nginx
RUN apt-get -y install openssl
RUN apt-get -y install vim
RUN apt-get -y install php7.3-fpm
RUN apt-get -y install mariadb-server
RUN apt-get -y install php-mysql
RUN apt-get -y install wget

COPY  ./srcs/run.sh ./
COPY  ./srcs/default ./tmp
COPY  ./srcs/wp-config.php ./tmp
COPY  ./srcs/config.inc.php ./tmp

EXPOSE  80 443

CMD bash run.sh
