cmake_minimum_required(VERSION 3.8)
project(joy_package)

# コンパイラオプションの設定
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ビルドタイプの設定（デバッグ用）
set(CMAKE_BUILD_TYPE Debug)

# 必要な依存パッケージの指定
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# インクルードディレクトリの追加
include_directories(include)

# ノードのリスト
set(NODES
  joy_publisher
  joy_subscriber
)

# 各ノードのビルド設定
foreach(node ${NODES})
  add_executable(${node} src/${node}.cpp)
  ament_target_dependencies(${node} rclcpp sensor_msgs std_msgs)
  install(TARGETS ${node}
    DESTINATION lib/${PROJECT_NAME})
endforeach()

# テストの設定（オプション）
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# パッケージのインストール設定
ament_package()

