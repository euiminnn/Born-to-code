# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 21:22:33 by echung            #+#    #+#              #
#    Updated: 2021/06/03 18:10:12 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM  debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade

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
