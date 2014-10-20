################################################################################
# Copyright © 2012-2014, Targoman.com
#
# Published under the terms of TCRL(Targoman Community Research License)
# You can find a copy of the license file with distributed source or
# download it from http://targoman.com/License.txt
#
################################################################################

DependencyIncludePaths+=
DependencyLibPaths+=
Dependencies +=

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
CONFIG(debug, debug|release): DEFINES += TARGOMAN_SHOW_DEBUG=1
DEFINES += TARGOMAN_DEBUG_PROCESS_LINE=1
DEFINES += TARGOMAN_SHOW_WARNING=1
DEFINES += TARGOMAN_SHOW_INFO=1
DEFINES += TARGOMAN_SHOW_HAPPY=1
DEFINES += TARGOMAN_SHOW_NORMAL=1


DEFINES += PROJ_VERSION=$$VERSION

#############################################################################################
#                     DO NOT CHANGE ANYTHING BELOW
#############################################################################################

!unix{
  error("********* Compile on OS other than Linux is not ready yet")
}

isEmpty(PREFIX) {
 PREFIX = $$(HOME)/local
}

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
isEmpty(BasePath) {
 BasePath = .
}
BaseOutput=$$BasePath/$$BaseOutput
message("*********************   $$ProjectName CONFIG  ***************************** ")
message("* Building $$ProjectName Ver. $$VERSION")
message("* Base Out Path has been set to: $$BaseOutput/")
message("* Install Path has been set to: $$PREFIX/")
message("****************************************************************** ")

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
QT += core

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
LibFolderPattern        = ./lib
LibIncludeFolderPattern = ./include
BinFolderPattern        = ./bin
BuildFolderPattern      = ./build
TestBinFolder           = ./test

BaseLibraryFolder        = $$BaseOutput/out/$$LibFolderPattern
BaseLibraryIncludeFolder = $$BaseOutput/out/$$LibIncludeFolderPattern
BaseBinFolder            = $$BaseOutput/out/$$BinFolderPattern
BaseTestBinFolder        = $$BaseOutput/out/$$TestBinFolder
BaseBuildFolder          = $$BaseOutput/out/$$BuildFolderPattern

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
INCLUDEPATH += $$BaseLibraryIncludeFolder \
               $$(PREFIX)/include \
               $$(DependencyIncludePaths)/

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
DependencyLibPaths      += $$BaseOutput/out/$$LibFolderPattern \
                         $$BaseLibraryFolder
FullDependencySearchPaths=   $$DependencyLibPaths

unix {
  DependencySearchPaths += $$(PREFIX)/lib \
                           $$(PREFIX)/lib/lib

  FullDependencySearchPaths+=  /usr/lib \
                               /usr/lib64 \
                               /usr/local/lib \
                               /usr/local/lib64
}

QMAKE_LIBDIR +=  $$DependencyLibPaths

for(Project, Dependencies) {
  for(Path, FullDependencySearchPaths):isEmpty( Found ) {
      message(Looking for $$Project in $$Path)
      exists($$Path/lib$$Project*) {
        Found = "TRUE"
        message(-------------> $$Project Found!!!)
      }
      message("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-")
  }
  isEmpty( Found ) {
    message("***********************************************************************************************")
    message("!!!!!! $$ProjectName Depends on $$Project but not found ")
    message("***********************************************************************************************")
    error("")
  }
  Found = ""
}


for(Library, Dependencies):LIBS += -l$$Library

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
unix{
  documentation.path = $$PREFIX/doc
  documentation.files=docs/*
#  documentation.extra=create_docs; mv master.doc toc.doc

  target.files= $$BaseOutput/out/$$BinFolderPattern \
                $$BaseOutput/out/$$LibFolderPattern \
                $$BaseOutput/out/$$LibIncludeFolderPattern

  target.path = $$PREFIX/
  target.extra= rm -rvf $$PREFIX/lib/lib/

  INSTALLS += documentation \
              target
}

#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
defineTest(addSubdirs) {
    for(subdirs, 1) {
        entries = $$files($$subdirs)
        for(entry, entries) {
            name = $$replace(entry, [/\\\\], _)
            SUBDIRS += $$name
            eval ($${name}.subdir = $$entry)
            for(dep, 2):eval ($${name}.depends += $$replace(dep, [/\\\\], _))
            export ($${name}.subdir)
            export ($${name}.depends)
        }
    }
    export (SUBDIRS)
}

