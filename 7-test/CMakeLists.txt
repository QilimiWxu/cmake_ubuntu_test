

# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

# 检查系统是否支持abs函数
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (abs ABS_EXISTS)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
       
# 是否加入 subSum 库
if (NOT ABS_EXISTS)
  include_directories ("${PROJECT_SOURCE_DIR}/sub1")
  add_subdirectory (sub1)  
  set (EXTRA_LIBS ${EXTRA_LIBS} subSum)
endif (NOT ABS_EXISTS)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})

# 指定安装路径
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)


# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# 使用该宏进行一系列的数据测试
do_test (5 2 "7")
do_test (10 5 "15")
do_test (2 10 "12")
do_test (15 10 "25")
do_test (2 14 "16")
do_test (2 -77 "79")
do_test (-1 -1 "2")
do_test (-2 5 "7")
