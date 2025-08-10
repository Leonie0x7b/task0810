cmake_minimum_required(VERSION 4.1.0)  # 推荐使用3.10及以上版本，兼容性更好
include_directories(.)
project(proj)
add_executable(proj src/main.c src/queue.c src/stack.c)