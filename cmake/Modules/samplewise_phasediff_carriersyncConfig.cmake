INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SAMPLEWISE_PHASEDIFF_CARRIERSYNC samplewise_phasediff_carriersync)

FIND_PATH(
    SAMPLEWISE_PHASEDIFF_CARRIERSYNC_INCLUDE_DIRS
    NAMES samplewise_phasediff_carriersync/api.h
    HINTS $ENV{SAMPLEWISE_PHASEDIFF_CARRIERSYNC_DIR}/include
        ${PC_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SAMPLEWISE_PHASEDIFF_CARRIERSYNC_LIBRARIES
    NAMES gnuradio-samplewise_phasediff_carriersync
    HINTS $ENV{SAMPLEWISE_PHASEDIFF_CARRIERSYNC_DIR}/lib
        ${PC_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SAMPLEWISE_PHASEDIFF_CARRIERSYNC DEFAULT_MSG SAMPLEWISE_PHASEDIFF_CARRIERSYNC_LIBRARIES SAMPLEWISE_PHASEDIFF_CARRIERSYNC_INCLUDE_DIRS)
MARK_AS_ADVANCED(SAMPLEWISE_PHASEDIFF_CARRIERSYNC_LIBRARIES SAMPLEWISE_PHASEDIFF_CARRIERSYNC_INCLUDE_DIRS)
