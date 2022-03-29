FROM centos:latest

RUN sed -i -e "s|mirrorlist=|#mirrorlist=|g" /etc/yum.repos.d/CentOS-*
RUN sed -i -e "s|#baseurl=http://mirror.centos.org|baseurl=http://vault.centos.org|g" /etc/yum.repos.d/CentOS-*
RUN yum update -y --quiet
RUN yum groupinstall -y --quiet "Development Tools"
RUN yum install -y --quiet boost-devel cmake