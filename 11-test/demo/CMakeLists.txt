cmake_minimum_required(VERSION 2.8)

project(myboost)

add_definitions(-std=c++11 -DHAVE_NETINET_IN_H)

#添加头文件搜索路径/usr/local/include/thrift /usr/local/include/
include_directories(/usr/local/include)

#添加库文件搜索路径
link_directories(/usr/local/lib)

#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中
aux_source_directory(. DIR_SRCS)

add_executable(myboost ${DIR_SRCS})

#在这里根据名字boost_thread去寻找libboost_thread.a文件
target_link_libraries(myboost thrift)
