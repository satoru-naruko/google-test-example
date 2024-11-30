cmake_minimum_required(VERSION 3.11)
project(GoogleTestExample)

# C++ 11 以降を使用
set(CMAKE_CXX_STANDARD 11)

# FetchContentを使ってGoogleTestを取得する
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)

# FetchContentでGoogleTestをクローン＆ビルドする
FetchContent_MakeAvailable(googletest)

# テスト対象のソースコードを変数に格納
file(GLOB APP_SOURCES "src/*.cpp")

# テスト用コード（testディレクトリ内のすべての .cpp と .c ファイルを追加）
file(GLOB TEST_SOURCES
    main.cpp
    "test/*.cpp"
    "test/*.c"
)

# テスト対象のライブラリを作成（add.cpp を含む）
add_library(test_target_lib ${APP_SOURCES})
if(MSVC)
target_compile_options(test_target_lib PRIVATE $<$<CONFIG:Debug>:/MTd>)
target_compile_options(test_target_lib PRIVATE $<$<CONFIG:Release>:/MT>)
endif()

# テスト用コードの実行可能ファイルを生成
add_executable(test_example ${TEST_SOURCES})

if(MSVC)
target_compile_options(test_example PRIVATE $<$<CONFIG:Debug>:/MTd>)
target_compile_options(test_example PRIVATE $<$<CONFIG:Release>:/MT>)
endif()

# Google Test をリンク
target_link_libraries(test_example test_target_lib gtest gtest_main)

# テストを実行できるように設定
enable_testing()
add_test(NAME test_example COMMAND test_example)