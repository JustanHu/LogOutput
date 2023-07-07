//
// Created by 83787 on 2023/7/6.
//

#ifndef LOGOUTPUT_LOGOUTPUT_H
#define LOGOUTPUT_LOGOUTPUT_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

// 日志级别枚举
enum class setLogLevel {
    Debug,
    Info,
    Warning,
    Error
};

class LogOutput {

private: //私有属性
    enum setLogLevel logLevel = setLogLevel::Info;  //日志等级属性，默认初始值为Info
    std::ofstream file; //接收日志输出的文件

protected: //保护方法
/**
 * @brief  格式化日志消息
 * @param  Level 日志级别
 * @param message 需要输出的基础信息
 * @return 格式化之后的消息
 */
    std::string formatMessage(setLogLevel level, const std::string& message);

/**
 * @brief  将日志级别转换为字符串表示
 * @param  Level 日志级别
 * @return 转换为字符串之后的日志级别
 */
    std::string logLevelToString(setLogLevel level) const;

/**
 * @brief  输出到日志目标
 * @param  message 格式化后的日志消息
 */
    void outputLog(const std::string& message);

public: //公有方法
/**
* @brief  构造函数
* @param  filename:需要打开的txt完整名字或路径
*/
    LogOutput(const std::string& filename);

/**
* @brief  析构函数
*/
    ~LogOutput();

/**
 * @brief  设置日志输出等级属性
 * @param  Level 需要设置的等级如：setLogLevel::Debug, setLogLevel::Info, setLogLevel::Warning, setLogLevel::Error
 */
    void setLevel(setLogLevel Level);

/**
 * @brief  设置日志输出等级属性
 * @param  Level 需要设置的等级如：setLogLevel::Debug, setLogLevel::Info, setLogLevel::Warning, setLogLevel::Error
 */
    void log(setLogLevel level, const std::string& message);

};

#endif //LOGOUTPUT_LOGOUTPUT_H
