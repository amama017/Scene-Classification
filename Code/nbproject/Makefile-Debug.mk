#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Pyramid.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Clusters.o \
	${OBJECTDIR}/Manager.o \
	${OBJECTDIR}/Classifiers.o \
	${OBJECTDIR}/Features.o \
	${OBJECTDIR}/IO.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config --cflags --libs opencv` 
CXXFLAGS=`pkg-config --cflags --libs opencv` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../OpenCV-2.4.1/build/lib -Llibs/vlfeat-0.9.16/bin/glnxa64 libs/vlfeat-0.9.16/bin/glnxa64/libvl.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: libs/vlfeat-0.9.16/bin/glnxa64/libvl.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS} `pkg-config --cflags --libs opencv`

${OBJECTDIR}/Pyramid.o: Pyramid.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Pyramid.o Pyramid.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Clusters.o: Clusters.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Clusters.o Clusters.cpp

${OBJECTDIR}/Manager.o: Manager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Manager.o Manager.cpp

${OBJECTDIR}/Classifiers.o: Classifiers.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Classifiers.o Classifiers.cpp

${OBJECTDIR}/Features.o: Features.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/Features.o Features.cpp

${OBJECTDIR}/IO.o: IO.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../OpenCV-2.4.1/include/opencv -I../../OpenCV-2.4.1/include/opencv2 -Ilibs/vlfeat-0.9.16 -I../../OpenCV-2.4.1/include -I../../OpenCV-2.4.1 `pkg-config --cflags --libs opencv` -MMD -MP -MF $@.d -o ${OBJECTDIR}/IO.o IO.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
