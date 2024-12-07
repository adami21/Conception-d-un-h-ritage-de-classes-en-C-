# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = guiElectionTP3
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += FormCandidat.cpp FormElecteur.cpp FormPrincipal.cpp main.cpp
HEADERS += FormCandidat.h FormElecteur.h FormPrincipal.h
FORMS += FormCandidat.ui FormElecteur.ui FormPrincipal.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../TP3Source 
LIBS += ../TP3Source/dist/Debug/GNU-Linux/libtp3source.a  
