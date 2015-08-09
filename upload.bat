@echo off
pscp -pw 123456 lefs.c root@192.168.80.5:/lefs
pscp -pw 123456 debug.h root@192.168.80.5:/lefs
pscp -pw 123456 Makefile root@192.168.80.5:/lefs
