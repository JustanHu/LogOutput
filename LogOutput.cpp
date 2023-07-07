//
// Created by 83787 on 2023/7/6.
//

#include "LogOutput.h"

LogOutput::LogOutput(const std::string& filename){
    file.open(filename, std::ios::app);  // 追加模式打开文件
}

LogOutput::~LogOutput(){
    if (file.is_open())
        file.close();
}

void LogOutput::setLevel(setLogLevel level){
    logLevel = level;
}

void LogOutput::log(setLogLevel level, const std::string& message){
    if (level >= logLevel) { //判断当前日志输出属性等级，只有大于等于logLevel的才进行输出
        std::string formattedMessage = formatMessage(level, message); //格式化日志消息
        outputLog(formattedMessage);//输出到日志目标（控制台或文件）
    }
}

std::string LogOutput::formatMessage(setLogLevel level, const std::string& message){
    std::string formattedMessage;

    // 添加日期和时间戳
    time_t now = std::time(nullptr);
    formattedMessage += std::asctime(std::localtime(&now));
    formattedMessage.pop_back();  // 移除末尾的换行符

    // 添加日志级别
    formattedMessage += " [" + logLevelToString(level) + "]";

    // 添加具体日志消息
    formattedMessage += ": " + message;

    return formattedMessage;
}

std::string LogOutput::logLevelToString(setLogLevel level) const{
    switch (level) {
        case setLogLevel::Debug:
            return "Debug";
        case setLogLevel::Info:
            return "Info";
        case setLogLevel::Warning:
            return "Warning";
        case setLogLevel::Error:
            return "Error";
        default:
            return "Unknown";
    }
}

void LogOutput::outputLog(const std::string& message){
    if (file.is_open()) {
        file << message << std::endl;
    }
//    std::cout << message << std::endl; //输出到控制台
}