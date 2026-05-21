##############################################################################
#   Copyright (C) 2022 GSI Helmholtzzentrum für Schwerionenforschung GmbH    #
#   Copyright (C) 2022-2025 Members of R3B Collaboration                     #
#                                                                            #
#             This software is distributed under the terms of the            #
#                 GNU General Public Licence (GPL) version 3,                #
#                    copied verbatim in the file "LICENSE".                  #
#                                                                            #
# In applying this license GSI does not waive the privileges and immunities  #
# granted to it by virtue of its status as an Intergovernmental Organization #
# or submit itself to any jurisdiction.                                      #
##############################################################################

file(
    GLOB
    SRCS
    calibration/*.cxx
    online/*.cxx
    )

change_file_extension(*.cxx *.h HEADERS "${SRCS}")

add_library_with_dictionary(
    LIBNAME
    R3BPas
    LINKDEF
    PasLinkDef.h
    HEADERS
    ${HEADERS}
    SRCS
    ${SRCS}
    INCLUDEDIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    calibration
    online
    DEPENDENCIES
    R3BPassive)

