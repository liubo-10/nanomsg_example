ZZ_INSTALL(DIRECTORY ./arm/shared/lib
        DESTINATION $ENV{HOVER_DIST_APPDIR}/
        COMPONENT core camera-tuning
        PKG nng
        )

ZZ_INSTALL(DIRECTORY ./aarch64/shared/lib/
        DESTINATION $ENV{HOVER_DIST_APPDIR}/lib64/
        COMPONENT core camera-tuning
        PKG nng
        )

