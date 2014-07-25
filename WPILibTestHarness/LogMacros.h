/*
 * LogMacros.h
 *
 *  Created on: Jan 1, 2014
 *      Author: jamie
 */

#ifndef LOGMACROS_H_
#define LOGMACROS_H_

#include <eurointroduction/EzLogger/LogMessage.h>
#include <eurointroduction/EzLogger/LogCore.h>
#include <memory>
#include <eurointroduction/EzLogger/Tags.h>
#include <unistd.h>

#define LOG_DEBUG(args)																				\
{																									\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Debug"}}));	\
	logMessage->stream() << args;\
	LogCore::instance().log(logMessage); \
}

#define LOG_INFO(args)																				\
{						rsmith@crackofdawn.onmicrosoft.com																			\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Info"}}));	\
	logMessage->stream() << args;\
	LogCore::instance().log(logMessage); \
}

#define LOG_ROBOT_RECOVERABLE(args)																				\
{																									\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Robot-Warning"}}));	\
	logMessage->stream() << args;\
	LogCore::instance().log(logMessage); \
}


#define LOG_ROBOT_FATAL(args)																				\
{																									\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Robot-Fatal"}}));	\
	logMessage->stream() << args;\
	LogCore::instance().log(logMessage); \
}


#define LOG_FATAL(args)																				\
{																									\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Fatal"}}));	\
	logMessage->stream() << args;\
	LogCore::instance().log(logMessage); \
	sleep(1); \
	exit(2); \
}

#define LOG_NOT_IMPLEMENTED																				\
{																									\
	std::shared_ptr<LogMessage> logMessage(new LogMessage({{"time", currentTime()}, {"severity", "Fatal"}}));	\
	logMessage->stream() << "Unimplemented function called: " << __PRETTY_FUNCTION__ << " in " << __FILE__ << ":" << __LINE__ ;\
	LogCore::instance().log(logMessage); \
	sleep(1); \
	exit(3); \
}


#endif /* LOGMACROS_H_ */
