QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/vendor/spdlog/include/ \
    $$PWD/vendor/json/single_include/

SOURCES += main.cpp \
    src/statemachine.cpp \
    src/application.cpp \
    src/loginstate.cpp \
    src/log.cpp \
    src/LoginDialog/logindialog.cpp \
    src/eventhandler.cpp \
    src/database.cpp \
    src/models/client.cpp \
    src/models/adress.cpp \
    src/models/user.cpp \
    src/mainwindowstate.cpp \
    src/MainWindow/mainwindow.cpp

HEADERS += \
    src/application.hpp \
    src/log.h \
    src/loginstate.hpp \
    src/state.hpp \
    src/statemachine.hpp \
    vendor/json/single_include/nlohmann/json.hpp \
    vendor/spdlog/include/spdlog/details/async_logger_impl.h \
    vendor/spdlog/include/spdlog/details/circular_q.h \
    vendor/spdlog/include/spdlog/details/console_globals.h \
    vendor/spdlog/include/spdlog/details/file_helper.h \
    vendor/spdlog/include/spdlog/details/fmt_helper.h \
    vendor/spdlog/include/spdlog/details/log_msg.h \
    vendor/spdlog/include/spdlog/details/logger_impl.h \
    vendor/spdlog/include/spdlog/details/mpmc_blocking_q.h \
    vendor/spdlog/include/spdlog/details/null_mutex.h \
    vendor/spdlog/include/spdlog/details/os.h \
    vendor/spdlog/include/spdlog/details/pattern_formatter.h \
    vendor/spdlog/include/spdlog/details/periodic_worker.h \
    vendor/spdlog/include/spdlog/details/registry.h \
    vendor/spdlog/include/spdlog/details/thread_pool.h \
    vendor/spdlog/include/spdlog/fmt/bundled/colors.h \
    vendor/spdlog/include/spdlog/fmt/bundled/core.h \
    vendor/spdlog/include/spdlog/fmt/bundled/format-inl.h \
    vendor/spdlog/include/spdlog/fmt/bundled/format.h \
    vendor/spdlog/include/spdlog/fmt/bundled/ostream.h \
    vendor/spdlog/include/spdlog/fmt/bundled/posix.h \
    vendor/spdlog/include/spdlog/fmt/bundled/printf.h \
    vendor/spdlog/include/spdlog/fmt/bundled/ranges.h \
    vendor/spdlog/include/spdlog/fmt/bundled/time.h \
    vendor/spdlog/include/spdlog/fmt/bin_to_hex.h \
    vendor/spdlog/include/spdlog/fmt/fmt.h \
    vendor/spdlog/include/spdlog/fmt/ostr.h \
    vendor/spdlog/include/spdlog/sinks/android_sink.h \
    vendor/spdlog/include/spdlog/sinks/ansicolor_sink.h \
    vendor/spdlog/include/spdlog/sinks/base_sink.h \
    vendor/spdlog/include/spdlog/sinks/basic_file_sink.h \
    vendor/spdlog/include/spdlog/sinks/daily_file_sink.h \
    vendor/spdlog/include/spdlog/sinks/dist_sink.h \
    vendor/spdlog/include/spdlog/sinks/msvc_sink.h \
    vendor/spdlog/include/spdlog/sinks/null_sink.h \
    vendor/spdlog/include/spdlog/sinks/ostream_sink.h \
    vendor/spdlog/include/spdlog/sinks/rotating_file_sink.h \
    vendor/spdlog/include/spdlog/sinks/sink.h \
    vendor/spdlog/include/spdlog/sinks/stdout_color_sinks.h \
    vendor/spdlog/include/spdlog/sinks/stdout_sinks.h \
    vendor/spdlog/include/spdlog/sinks/syslog_sink.h \
    vendor/spdlog/include/spdlog/sinks/wincolor_sink.h \
    vendor/spdlog/include/spdlog/async.h \
    vendor/spdlog/include/spdlog/async_logger.h \
    vendor/spdlog/include/spdlog/common.h \
    vendor/spdlog/include/spdlog/formatter.h \
    vendor/spdlog/include/spdlog/logger.h \
    vendor/spdlog/include/spdlog/spdlog.h \
    vendor/spdlog/include/spdlog/tweakme.h \
    vendor/spdlog/include/spdlog/version.h \
    src/LoginDialog/logindialog.h \
    src/eventhandler.h \
    src/appdata.h \
    src/database.h \
    src/models/client.h \
    src/models/adress.h \
    src/models/user.h \
    src/mainwindowstate.h \
    src/MainWindow/mainwindow.h

DISTFILES += \
    vendor/spdlog/include/spdlog/fmt/bundled/LICENSE.rst \
    vendor/spdlog/include/spdlog/fmt/bundled/LICENSE.rst \
    LICENSE \
    resources/logo/Luna_Cars_Client_Logo.png \
    vendor/json/LICENSE.MIT

FORMS +=

RESOURCES +=
