QT -= gui

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

INCLUDEPATH += $$PWD/libs/

SOURCES += main.cpp \
    src/statemachine.cpp \
    src/application.cpp \
    src/loginstate.cpp \
    src/log.cpp

HEADERS += \
    src/state.hpp \
    src/statemachine.hpp \
    src/application.hpp \
    src/loginstate.hpp \
    libs/spdlog/details/async_logger_impl.h \
    libs/spdlog/details/circular_q.h \
    libs/spdlog/details/console_globals.h \
    libs/spdlog/details/file_helper.h \
    libs/spdlog/details/fmt_helper.h \
    libs/spdlog/details/log_msg.h \
    libs/spdlog/details/logger_impl.h \
    libs/spdlog/details/mpmc_blocking_q.h \
    libs/spdlog/details/null_mutex.h \
    libs/spdlog/details/os.h \
    libs/spdlog/details/pattern_formatter.h \
    libs/spdlog/details/periodic_worker.h \
    libs/spdlog/details/registry.h \
    libs/spdlog/details/thread_pool.h \
    libs/spdlog/fmt/bundled/colors.h \
    libs/spdlog/fmt/bundled/core.h \
    libs/spdlog/fmt/bundled/format-inl.h \
    libs/spdlog/fmt/bundled/format.h \
    libs/spdlog/fmt/bundled/ostream.h \
    libs/spdlog/fmt/bundled/posix.h \
    libs/spdlog/fmt/bundled/printf.h \
    libs/spdlog/fmt/bundled/ranges.h \
    libs/spdlog/fmt/bundled/time.h \
    libs/spdlog/fmt/bin_to_hex.h \
    libs/spdlog/fmt/fmt.h \
    libs/spdlog/fmt/ostr.h \
    libs/spdlog/sinks/android_sink.h \
    libs/spdlog/sinks/ansicolor_sink.h \
    libs/spdlog/sinks/base_sink.h \
    libs/spdlog/sinks/basic_file_sink.h \
    libs/spdlog/sinks/daily_file_sink.h \
    libs/spdlog/sinks/dist_sink.h \
    libs/spdlog/sinks/msvc_sink.h \
    libs/spdlog/sinks/null_sink.h \
    libs/spdlog/sinks/ostream_sink.h \
    libs/spdlog/sinks/rotating_file_sink.h \
    libs/spdlog/sinks/sink.h \
    libs/spdlog/sinks/stdout_color_sinks.h \
    libs/spdlog/sinks/stdout_sinks.h \
    libs/spdlog/sinks/syslog_sink.h \
    libs/spdlog/sinks/wincolor_sink.h \
    libs/spdlog/async.h \
    libs/spdlog/async_logger.h \
    libs/spdlog/common.h \
    libs/spdlog/formatter.h \
    libs/spdlog/logger.h \
    libs/spdlog/spdlog.h \
    libs/spdlog/tweakme.h \
    libs/spdlog/version.h \
    src/log.h

DISTFILES += \
    libs/spdlog/fmt/bundled/LICENSE.rst
