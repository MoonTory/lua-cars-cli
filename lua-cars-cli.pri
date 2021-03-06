# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ./src/Models/address.h \
    ./vendor/spdlog/include/spdlog/sinks/android_sink.h \
    ./vendor/spdlog/include/spdlog/sinks/ansicolor_sink.h \
    ./src/appdata.h \
    ./vendor/spdlog/include/spdlog/async.h \
    ./vendor/spdlog/include/spdlog/async_logger.h \
    ./vendor/spdlog/include/spdlog/details/async_logger_impl.h \
    ./vendor/spdlog/include/spdlog/sinks/base_sink.h \
    ./vendor/spdlog/include/spdlog/sinks/basic_file_sink.h \
    ./vendor/spdlog/include/spdlog/fmt/bin_to_hex.h \
    ./vendor/spdlog/include/spdlog/details/circular_q.h \
    ./src/Models/client.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/colors.h \
    ./vendor/spdlog/include/spdlog/common.h \
    ./vendor/spdlog/include/spdlog/details/console_globals.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/core.h \
    ./vendor/spdlog/include/spdlog/sinks/daily_file_sink.h \
    ./vendor/spdlog/include/spdlog/sinks/dist_sink.h \
    ./src/eventhandler.h \
    ./vendor/spdlog/include/spdlog/details/file_helper.h \
    ./vendor/spdlog/include/spdlog/fmt/fmt.h \
    ./vendor/spdlog/include/spdlog/details/fmt_helper.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/format-inl.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/format.h \
    ./vendor/spdlog/include/spdlog/formatter.h \
    ./vendor/json/single_include/nlohmann/json.hpp \
    ./src/log.h \
    ./vendor/spdlog/include/spdlog/details/log_msg.h \
    ./vendor/spdlog/include/spdlog/logger.h \
    ./vendor/spdlog/include/spdlog/details/logger_impl.h \
    ./src/loginstate.hpp \
    ./src/mainwindowstate.h \
    ./vendor/spdlog/include/spdlog/details/mpmc_blocking_q.h \
    ./vendor/spdlog/include/spdlog/sinks/msvc_sink.h \
    ./vendor/spdlog/include/spdlog/details/null_mutex.h \
    ./vendor/spdlog/include/spdlog/sinks/null_sink.h \
    ./vendor/spdlog/include/spdlog/details/os.h \
    ./vendor/spdlog/include/spdlog/fmt/ostr.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/ostream.h \
    ./vendor/spdlog/include/spdlog/sinks/ostream_sink.h \
    ./vendor/spdlog/include/spdlog/details/pattern_formatter.h \
    ./vendor/spdlog/include/spdlog/details/periodic_worker.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/posix.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/printf.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/ranges.h \
    ./vendor/spdlog/include/spdlog/details/registry.h \
    ./vendor/spdlog/include/spdlog/sinks/rotating_file_sink.h \
    ./vendor/spdlog/include/spdlog/sinks/sink.h \
    ./vendor/spdlog/include/spdlog/spdlog.h \
    ./src/state.hpp \
    ./src/statemachine.hpp \
    ./vendor/spdlog/include/spdlog/sinks/stdout_color_sinks.h \
    ./vendor/spdlog/include/spdlog/sinks/stdout_sinks.h \
    ./vendor/spdlog/include/spdlog/sinks/syslog_sink.h \
    ./vendor/spdlog/include/spdlog/details/thread_pool.h \
    ./vendor/spdlog/include/spdlog/fmt/bundled/time.h \
    ./vendor/spdlog/include/spdlog/tweakme.h \
    ./src/Models/user.h \
    ./vendor/spdlog/include/spdlog/version.h \
    ./vendor/spdlog/include/spdlog/sinks/wincolor_sink.h \
    ./src/application.hpp \
    ./src/Forms/LoginDialog/logindialog.h \
    ./src/Forms/MainWindow/mainwindow.h
SOURCES += ./src/Models/address.cpp \
    ./src/application.cpp \
    ./src/Models/client.cpp \
    ./src/eventhandler.cpp \
    ./src/log.cpp \
    ./src/Forms/LoginDialog/logindialog.cpp \
    ./src/loginstate.cpp \
    ./main.cpp \
    ./src/Forms/MainWindow/mainwindow.cpp \
    ./src/mainwindowstate.cpp \
    ./src/statemachine.cpp \
    ./src/Models/user.cpp
RESOURCES += res.qrc
